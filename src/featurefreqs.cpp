#include "myutils.h"
#include "features.h"
#include "dss.h"

// Freqs AA/20
static float Freqs_AA[20] = {
   0.081053,
   0.013989,
   0.057990,
   0.070191,
   0.040391,
   0.072408,
   0.023216,
   0.057991,
   0.059277,
   0.094527,
   0.017958,
   0.041622,
   0.046079,
   0.037216,
   0.052758,
   0.059484,
   0.053736,
   0.071781,
   0.013693,
   0.034642 };

// Freqs NbrDist/16
static float Freqs_NbrDist[16] = {
   0.053605,
   0.051742,
   0.051096,
   0.052109,
   0.053606,
   0.055746,
   0.060282,
   0.062136,
   0.061794,
   0.061931,
   0.061731,
   0.062851,
   0.064271,
   0.065907,
   0.072345,
   0.108846 };

// Freqs MySS/16
static float Freqs_MySS[16] = {
   0.270353,
   0.107096,
   0.084089,
   0.051954,
   0.051163,
   0.048313,
   0.046750,
   0.045154,
   0.043377,
   0.041906,
   0.041519,
   0.042631,
   0.035407,
   0.032071,
   0.031482,
   0.026736 };

// Freqs NbrMySS/16
static float Freqs_NbrMySS[16] = {
   0.220077,
   0.139949,
   0.129379,
   0.061022,
   0.040259,
   0.053470,
   0.038375,
   0.036814,
   0.026336,
   0.044509,
   0.042476,
   0.036842,
   0.035511,
   0.038386,
   0.031057,
   0.025539 };

// Freqs RevNbrDist/16
static float Freqs_RevNbrDist[16] = {
   0.050040,
   0.026371,
   0.044586,
   0.070471,
   0.098372,
   0.234389,
   0.065342,
   0.053976,
   0.046884,
   0.040206,
   0.033792,
   0.030481,
   0.027747,
   0.026339,
   0.034545,
   0.116460 };

// Freqs DstNxtHlx/16
static float Freqs_DstNxtHlx[16] = {
   0.327013,
   0.003260,
   0.006039,
   0.010993,
   0.017459,
   0.024919,
   0.029890,
   0.034812,
   0.039629,
   0.046173,
   0.043129,
   0.073294,
   0.065466,
   0.104032,
   0.069177,
   0.104715 };

// Freqs StrandDens/16
static float Freqs_StrandDens[16] = {
   0.096288,
   0.096320,
   0.068715,
   0.058490,
   0.054377,
   0.052562,
   0.052088,
   0.052514,
   0.053356,
   0.055008,
   0.057039,
   0.059644,
   0.060077,
   0.059084,
   0.057764,
   0.066675 };

// Freqs NormDens/16
static float Freqs_NormDens[16] = {
   0.108003,
   0.076361,
   0.069455,
   0.065213,
   0.062921,
   0.061204,
   0.059333,
   0.057394,
   0.056333,
   0.054970,
   0.054102,
   0.054157,
   0.053031,
   0.052306,
   0.051494,
   0.063724 };

float *g_FeatureFreqsVec[FEATURE_COUNT];
static bool Init()
	{
#define f(x)	g_FeatureFreqsVec[FEATURE_##x] = Freqs_##x
	f(AA);
	f(NbrDist);
	f(MySS);
	f(NbrMySS);
	f(RevNbrDist);
	f(DstNxtHlx);
	f(StrandDens);
	f(NormDens);
	return true;
	}
static bool InitDone = Init();