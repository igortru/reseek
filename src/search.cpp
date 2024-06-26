#include "myutils.h"
#include "dbsearcher.h"
#include "mx.h"
#include "pdbchain.h"
#include "xdpmem.h"
#include "cigar.h"
#include "timing.h"
#include <thread>

void cmd_search()
	{
	const string &QCalFN = g_Arg1;
	const string &DBFN = opt_db;
	DBSearcher DBS;
	DSSParams Params;
	Params.SetFromCmdLine();
	DBS.ReadChains(QCalFN, DBFN);
	Params.m_DBSize = (float) DBS.GetDBSize();
	if (optset_dbsize)
		Params.m_DBSize = (float) opt_dbsize;

	DBS.Setup(Params);
	DBS.m_fTsv = CreateStdioFile(opt_output);
	DBS.m_fAln = CreateStdioFile(opt_aln);
	DBS.m_fFasta2 = CreateStdioFile(opt_fasta2);
	ResetTimers();
	DBS.Run();
	//DSSAligner::Stats();

	//uint Hits = DBS.m_QPCacheHits;
	//uint Misses = DBS.m_QPCacheMisses;
	//ProgressLog("QP cache hits %u, misses %u\n", Hits, Misses);
	CloseStdioFile(DBS.m_fTsv);
	}
