#include "myutils.h"
#include "alpha.h"

extern double g_Blosum62[20][20];

void LogAln(const char *A, const char *B, const char *Path, unsigned ColCount)
	{
	unsigned p = 0;
	for (unsigned i = 0; i < ColCount; ++i)
		{
		char c = Path[i];
		if (c == 0)
			break;
		if (c == 'S')
			c = 'M';
		if (c == 'M' || c == 'D')
			Log("%c", A[p++]);
		else
			Log("-");
		}
	Log("\n");

	unsigned pa = 0;
	unsigned pb = 0;
	for (unsigned i = 0; i < ColCount; ++i)
		{
		char c = Path[i];
		if (c == 0)
			break;
		if (c == 'S')
			c = 'M';
		if (c == 'M')
			{
			byte a = A[pa];
			byte b = B[pb];
			byte Lettera = g_CharToLetterAmino[a];
			byte Letterb = g_CharToLetterAmino[b];
			if (toupper(a) == toupper(b))
				Log("|");
			else if (g_Blosum62[Lettera][Letterb] > 0.0f)
				Log("+");
			else
				Log(" ");
			}
		else
			Log(" ");
		if (c == 'M' || c == 'D')
			++pa;
		if (c == 'M' || c == 'I')
			++pb;
		}
	Log("\n");

	p = 0;
	for (unsigned i = 0; i < ColCount; ++i)
		{
		char c = Path[i];
		if (c == 0)
			break;
		if (c == 'S')
			c = 'M';
		if (c == 'M' || c == 'I')
			Log("%c", B[p++]);
		else
			Log("-");
		}
	Log("\n");
	}
