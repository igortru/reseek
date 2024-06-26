#pragma once

#include "dssparams.h"
#include "pdbchain.h"
#include "xdpmem.h"
#include "dss.h"
#include "mx.h"
#include <mutex>

class DSSAligner
	{
public:
	const DSSParams *m_Params = 0;
	const PDBChain *m_ChainA = 0;
	const PDBChain *m_ChainB = 0;
	const vector<vector<byte> > *m_ProfileA = 0;
	const vector<vector<byte> > *m_ProfileB = 0;
	const vector<byte> *m_ComboLettersA = 0;
	const vector<byte> *m_ComboLettersB = 0;
	const vector<uint> *m_ComboKmerBitsA = 0;
	const vector<uint> *m_ComboKmerBitsB = 0;
	vector<const float *> m_ProfCombo;
	vector<const float *> m_ProfComboRev;
	vector<const int8_t *> m_ProfComboi;
	vector<const int8_t *> m_ProfComboRevi;
	void *m_ProfPara = 0;
	void *m_ProfParaRev = 0;

	XDPMem m_Mem;
	Mx<float> m_SMx;
	Mx<float> m_RevSMx;

	Mx<int8_t> m_SMx_Int;
	Mx<int8_t> m_RevSMx_Int;

	uint m_AlnDomIdx1 = UINT_MAX;
	uint m_AlnDomIdx2 = UINT_MAX;
	string m_PathAB;
	uint m_LoA = UINT_MAX;
	uint m_LoB = UINT_MAX;
	float m_EvalueAB = FLT_MAX;
	float m_EvalueBA = FLT_MAX;
	float m_TestStatisticAB = FLT_MAX;
	float m_TestStatisticBA = FLT_MAX;

	float *m_DProw = 0;
	uint m_DProwSize = 0;
	float m_AlnFwdScore = FLT_MAX;

//public:
//	static bool m_UsePara;

public:
	static mutex m_OutputLock;
	static mutex m_StatsLock;

public:
	static uint m_AlnCount;
	static uint m_SWCount;
	static uint m_ComboFilterCount;
	static uint m_UFilterCount;
	static uint m_ParasailSaturateCount;

public:
	void SetQuery(
	  const PDBChain &Chain,
	  const vector<vector<byte> > *ptrProfile,
	  const vector<uint> *ptrComboKmerBits,
	  const vector<byte> *ptrComboLetters);

	void SetTarget(
	  const PDBChain &Chain,
	  const vector<vector<byte> > *ptrProfile,
	  const vector<uint> *ptrComboKmerBits,
	  const vector<byte> *ptrComboLetters);

	float GetComboScore();
	bool ComboFilter();
	bool UFilter();
	void AlignComboOnly();
	void AlignComboPath();
	void AlignQueryTarget();
	void Align_Test(
	  const PDBChain &ChainA, const PDBChain &ChainB,
	  const vector<byte> &ComboLettersA, const vector<byte> &ComboLettersB,
	  const vector<vector<byte> > &ProfileA, const vector<vector<byte> > &ProfileB);
	void Align_ComboFilter(
	  const PDBChain &ChainA, const PDBChain &ChainB,
	  const vector<byte> &ComboLettersA, const vector<byte> &ComboLettersB,
	  const vector<vector<byte> > &ProfileA, const vector<vector<byte> > &ProfileB);
	void Align_NoAccel();
	float AlignCombo(
	  const vector<byte> &LettersA, const vector<byte> &LettersB,
	  uint &LoA, uint &LoB, string &Path);
	float AlignComboQP(const vector<byte> &LettersA, const vector<byte> &LettersB);
	float AlignComboQP_Para();
	float AlignComboQP_Para_Path(uint &LoA, uint &LoB, string &Path);
	float AlignCombo_Int(const vector<byte> &LettersA, const vector<byte> &LettersB);
	float GetDPScorePath(const vector<vector<byte> > &ProfileA,
	  const vector<vector<byte> > &ProfileB, uint LoA, uint LoB,
	  const string &Path) const;
	//float GetDPScorePathVecs(
	//  const vector<vector<byte> > &ProfileA, const vector<vector<byte> > &ProfileB,
	//  uint LoA, uint LoB, const string &Path,
	//  vector<uint> &PosAs, vector<uint> &PosBs, vector<float> &ColScores) const;
	float GetComboDPScorePath(const vector<byte> &LettersA,
	  const vector<byte> &LettersB, uint LoA, uint LoB,
	  float GapOpen, float GapExt, const string &Path) const;
	int GetComboDPScorePathInt(const vector<byte> &ComboLettersA,
	  const vector<byte> &ComboLettersB, uint LoA, uint LoB,
	  const string &Path) const;
	float GetEvaluePath(  const PDBChain &ChainA, const PDBChain &ChainB,
	  const vector<vector<byte> > &ProfileA, const vector<vector<byte> > &ProfileB,
	  uint LoA, uint LoB, const string &Path) const;
	float GetScorePosPair(const vector<vector<byte> > &ProfileA,
	  const vector<vector<byte> > &ProfileB, uint PosA, uint PosB) const;
	float GetScoreSegPair(const vector<vector<byte> > &ProfileA,
	  const vector<vector<byte> > &ProfileB, uint PosA, uint PosB, uint n) const;
	uint GetU(const vector<uint> &Kmers1, const vector<uint> &Kmers2) const;
	void CalcEvalue();
	void SetSMx_YesRev();
	void SetSMx_NoRev();
	void SetComboQP();
	void SetComboQPi();
	void SetComboQP_Para();
	void SetSMx_Combo();
	void SetSMx_Combo_Int();
	void AllocDProw(uint LB);
	void ToTsv(FILE *f, float MaxEvalue);
	void ToFasta2(FILE *f, float MaxEvalue);
	void ToTsvBA(FILE *f, float MaxEvalue);
	void ToAln(FILE *f, float MaxEvalue);
	void ToAlnBA(FILE *f, float MaxEvalue);

public:
	static void Stats();
	};
