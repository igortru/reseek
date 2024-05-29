#include "myutils.h"

float ScoreMx_Combo[36][36] = {
  {  3.03f, -0.75f,  1.02f,  0.83f, -2.95f, -1.19f,  1.65f, -2.12f, -0.36f,  1.19f, -2.59f, -0.83f, -1.02f, -4.80f, -3.03f, -0.19f, -3.97f, -2.21f,  0.18f, -3.60f, -1.84f, -2.03f, -5.81f, -4.04f, -1.20f, -4.98f, -3.22f, -0.82f, -4.60f, -2.83f, -3.02f, -6.80f, -5.04f, -2.20f, -5.98f, -4.21f,  }, // 0
  { -0.75f,  3.58f,  1.57f, -2.95f,  1.38f, -0.64f, -2.12f,  2.21f,  0.19f, -2.59f,  1.74f, -0.28f, -4.80f, -0.47f, -2.48f, -3.97f,  0.36f, -1.66f, -3.60f,  0.73f, -1.29f, -5.81f, -1.48f, -3.49f, -4.98f, -0.65f, -2.67f, -4.60f, -0.27f, -2.28f, -6.80f, -2.47f, -4.49f, -5.98f, -1.64f, -3.66f,  }, // 1
  {  1.02f,  1.57f,  2.59f, -1.19f, -0.64f,  0.39f, -0.36f,  0.19f,  1.21f, -0.83f, -0.28f,  0.75f, -3.03f, -2.48f, -1.46f, -2.21f, -1.66f, -0.63f, -1.84f, -1.29f, -0.26f, -4.04f, -3.49f, -2.47f, -3.22f, -2.67f, -1.64f, -2.83f, -2.28f, -1.26f, -5.04f, -4.49f, -3.46f, -4.21f, -3.66f, -2.64f,  }, // 2
  {  0.83f, -2.95f, -1.19f,  3.35f, -0.43f,  1.33f,  1.97f, -1.81f, -0.05f, -1.02f, -4.80f, -3.03f,  1.50f, -2.28f, -0.51f,  0.12f, -3.66f, -1.89f, -2.03f, -5.81f, -4.04f,  0.49f, -3.29f, -1.52f, -0.89f, -4.67f, -2.90f, -3.02f, -6.80f, -5.04f, -0.50f, -4.28f, -2.52f, -1.88f, -5.66f, -3.90f,  }, // 3
  { -2.95f,  1.38f, -0.64f, -0.43f,  3.90f,  1.88f, -1.81f,  2.52f,  0.50f, -4.80f, -0.47f, -2.48f, -2.28f,  2.06f,  0.04f, -3.66f,  0.67f, -1.34f, -5.81f, -1.48f, -3.49f, -3.29f,  1.04f, -0.97f, -4.67f, -0.34f, -2.35f, -6.80f, -2.47f, -4.49f, -4.28f,  0.05f, -1.97f, -5.66f, -1.33f, -3.35f,  }, // 4
  { -1.19f, -0.64f,  0.39f,  1.33f,  1.88f,  2.91f, -0.05f,  0.50f,  1.53f, -3.03f, -2.48f, -1.46f, -0.51f,  0.04f,  1.06f, -1.89f, -1.34f, -0.32f, -4.04f, -3.49f, -2.47f, -1.52f, -0.97f,  0.05f, -2.90f, -2.35f, -1.33f, -5.04f, -4.49f, -3.46f, -2.52f, -1.97f, -0.94f, -3.90f, -3.35f, -2.32f,  }, // 5
  {  1.65f, -2.12f, -0.36f,  1.97f, -1.81f, -0.05f,  2.70f, -1.08f,  0.69f, -0.19f, -3.97f, -2.21f,  0.12f, -3.66f, -1.89f,  0.86f, -2.92f, -1.16f, -1.20f, -4.98f, -3.22f, -0.89f, -4.67f, -2.90f, -0.15f, -3.93f, -2.17f, -2.20f, -5.98f, -4.21f, -1.88f, -5.66f, -3.90f, -1.15f, -4.93f, -3.16f,  }, // 6
  { -2.12f,  2.21f,  0.19f, -1.81f,  2.52f,  0.50f, -1.08f,  3.25f,  1.24f, -3.97f,  0.36f, -1.66f, -3.66f,  0.67f, -1.34f, -2.92f,  1.41f, -0.61f, -4.98f, -0.65f, -2.67f, -4.67f, -0.34f, -2.35f, -3.93f,  0.40f, -1.62f, -5.98f, -1.64f, -3.66f, -5.66f, -1.33f, -3.35f, -4.93f, -0.60f, -2.61f,  }, // 7
  { -0.36f,  0.19f,  1.21f, -0.05f,  0.50f,  1.53f,  0.69f,  1.24f,  2.26f, -2.21f, -1.66f, -0.63f, -1.89f, -1.34f, -0.32f, -1.16f, -0.61f,  0.42f, -3.22f, -2.67f, -1.64f, -2.90f, -2.35f, -1.33f, -2.17f, -1.62f, -0.59f, -4.21f, -3.66f, -2.64f, -3.90f, -3.35f, -2.32f, -3.16f, -2.61f, -1.59f,  }, // 8
  {  1.19f, -2.59f, -0.83f, -1.02f, -4.80f, -3.03f, -0.19f, -3.97f, -2.21f,  2.08f, -1.69f,  0.07f, -0.12f, -3.90f, -2.13f,  0.71f, -3.07f, -1.31f,  1.17f, -2.61f, -0.85f, -1.03f, -4.81f, -3.05f, -0.21f, -3.99f, -2.23f,  0.61f, -3.17f, -1.40f, -1.59f, -5.37f, -3.61f, -0.77f, -4.54f, -2.78f,  }, // 9
  { -2.59f,  1.74f, -0.28f, -4.80f, -0.47f, -2.48f, -3.97f,  0.36f, -1.66f, -1.69f,  2.64f,  0.62f, -3.90f,  0.43f, -1.58f, -3.07f,  1.26f, -0.76f, -2.61f,  1.72f, -0.30f, -4.81f, -0.48f, -2.50f, -3.99f,  0.34f, -1.67f, -3.17f,  1.16f, -0.85f, -5.37f, -1.04f, -3.05f, -4.54f, -0.21f, -2.23f,  }, // 10
  { -0.83f, -0.28f,  0.75f, -3.03f, -2.48f, -1.46f, -2.21f, -1.66f, -0.63f,  0.07f,  0.62f,  1.65f, -2.13f, -1.58f, -0.56f, -1.31f, -0.76f,  0.27f, -0.85f, -0.30f,  0.73f, -3.05f, -2.50f, -1.47f, -2.23f, -1.67f, -0.65f, -1.40f, -0.85f,  0.17f, -3.61f, -3.05f, -2.03f, -2.78f, -2.23f, -1.21f,  }, // 11
  { -1.02f, -4.80f, -3.03f,  1.50f, -2.28f, -0.51f,  0.12f, -3.66f, -1.89f, -0.12f, -3.90f, -2.13f,  2.40f, -1.38f,  0.39f,  1.02f, -2.76f, -0.99f, -1.03f, -4.81f, -3.05f,  1.49f, -2.29f, -0.53f,  0.10f, -3.67f, -1.91f, -1.59f, -5.37f, -3.61f,  0.93f, -2.85f, -1.09f, -0.45f, -4.23f, -2.47f,  }, // 12
  { -4.80f, -0.47f, -2.48f, -2.28f,  2.06f,  0.04f, -3.66f,  0.67f, -1.34f, -3.90f,  0.43f, -1.58f, -1.38f,  2.95f,  0.94f, -2.76f,  1.57f, -0.44f, -4.81f, -0.48f, -2.50f, -2.29f,  2.04f,  0.02f, -3.67f,  0.66f, -1.36f, -5.37f, -1.04f, -3.05f, -2.85f,  1.48f, -0.53f, -4.23f,  0.10f, -1.91f,  }, // 13
  { -3.03f, -2.48f, -1.46f, -0.51f,  0.04f,  1.06f, -1.89f, -1.34f, -0.32f, -2.13f, -1.58f, -0.56f,  0.39f,  0.94f,  1.96f, -0.99f, -0.44f,  0.58f, -3.05f, -2.50f, -1.47f, -0.53f,  0.02f,  1.05f, -1.91f, -1.36f, -0.34f, -3.61f, -3.05f, -2.03f, -1.09f, -0.53f,  0.49f, -2.47f, -1.91f, -0.89f,  }, // 14
  { -0.19f, -3.97f, -2.21f,  0.12f, -3.66f, -1.89f,  0.86f, -2.92f, -1.16f,  0.71f, -3.07f, -1.31f,  1.02f, -2.76f, -0.99f,  1.75f, -2.02f, -0.26f, -0.21f, -3.99f, -2.23f,  0.10f, -3.67f, -1.91f,  0.84f, -2.94f, -1.18f, -0.77f, -4.54f, -2.78f, -0.45f, -4.23f, -2.47f,  0.28f, -3.50f, -1.73f,  }, // 15
  { -3.97f,  0.36f, -1.66f, -3.66f,  0.67f, -1.34f, -2.92f,  1.41f, -0.61f, -3.07f,  1.26f, -0.76f, -2.76f,  1.57f, -0.44f, -2.02f,  2.31f,  0.29f, -3.99f,  0.34f, -1.67f, -3.67f,  0.66f, -1.36f, -2.94f,  1.39f, -0.63f, -4.54f, -0.21f, -2.23f, -4.23f,  0.10f, -1.91f, -3.50f,  0.83f, -1.18f,  }, // 16
  { -2.21f, -1.66f, -0.63f, -1.89f, -1.34f, -0.32f, -1.16f, -0.61f,  0.42f, -1.31f, -0.76f,  0.27f, -0.99f, -0.44f,  0.58f, -0.26f,  0.29f,  1.31f, -2.23f, -1.67f, -0.65f, -1.91f, -1.36f, -0.34f, -1.18f, -0.63f,  0.40f, -2.78f, -2.23f, -1.21f, -2.47f, -1.91f, -0.89f, -1.73f, -1.18f, -0.16f,  }, // 17
  {  0.18f, -3.60f, -1.84f, -2.03f, -5.81f, -4.04f, -1.20f, -4.98f, -3.22f,  1.17f, -2.61f, -0.85f, -1.03f, -4.81f, -3.05f, -0.21f, -3.99f, -2.23f,  2.70f, -1.08f,  0.69f,  0.50f, -3.28f, -1.52f,  1.32f, -2.46f, -0.69f,  1.30f, -2.47f, -0.71f, -0.90f, -4.68f, -2.91f, -0.07f, -3.85f, -2.09f,  }, // 18
  { -3.60f,  0.73f, -1.29f, -5.81f, -1.48f, -3.49f, -4.98f, -0.65f, -2.67f, -2.61f,  1.72f, -0.30f, -4.81f, -0.48f, -2.50f, -3.99f,  0.34f, -1.67f, -1.08f,  3.25f,  1.24f, -3.28f,  1.05f, -0.97f, -2.46f,  1.87f, -0.14f, -2.47f,  1.86f, -0.16f, -4.68f, -0.35f, -2.36f, -3.85f,  0.48f, -1.54f,  }, // 19
  { -1.84f, -1.29f, -0.26f, -4.04f, -3.49f, -2.47f, -3.22f, -2.67f, -1.64f, -0.85f, -0.30f,  0.73f, -3.05f, -2.50f, -1.47f, -2.23f, -1.67f, -0.65f,  0.69f,  1.24f,  2.26f, -1.52f, -0.97f,  0.06f, -0.69f, -0.14f,  0.88f, -0.71f, -0.16f,  0.86f, -2.91f, -2.36f, -1.34f, -2.09f, -1.54f, -0.51f,  }, // 20
  { -2.03f, -5.81f, -4.04f,  0.49f, -3.29f, -1.52f, -0.89f, -4.67f, -2.90f, -1.03f, -4.81f, -3.05f,  1.49f, -2.29f, -0.53f,  0.10f, -3.67f, -1.91f,  0.50f, -3.28f, -1.52f,  3.02f, -0.76f,  1.00f,  1.64f, -2.14f, -0.38f, -0.90f, -4.68f, -2.91f,  1.62f, -2.16f, -0.39f,  0.24f, -3.54f, -1.77f,  }, // 21
  { -5.81f, -1.48f, -3.49f, -3.29f,  1.04f, -0.97f, -4.67f, -0.34f, -2.35f, -4.81f, -0.48f, -2.50f, -2.29f,  2.04f,  0.02f, -3.67f,  0.66f, -1.36f, -3.28f,  1.05f, -0.97f, -0.76f,  3.57f,  1.55f, -2.14f,  2.19f,  0.17f, -4.68f, -0.35f, -2.36f, -2.16f,  2.17f,  0.16f, -3.54f,  0.79f, -1.22f,  }, // 22
  { -4.04f, -3.49f, -2.47f, -1.52f, -0.97f,  0.05f, -2.90f, -2.35f, -1.33f, -3.05f, -2.50f, -1.47f, -0.53f,  0.02f,  1.05f, -1.91f, -1.36f, -0.34f, -1.52f, -0.97f,  0.06f,  1.00f,  1.55f,  2.58f, -0.38f,  0.17f,  1.20f, -2.91f, -2.36f, -1.34f, -0.39f,  0.16f,  1.18f, -1.77f, -1.22f, -0.20f,  }, // 23
  { -1.20f, -4.98f, -3.22f, -0.89f, -4.67f, -2.90f, -0.15f, -3.93f, -2.17f, -0.21f, -3.99f, -2.23f,  0.10f, -3.67f, -1.91f,  0.84f, -2.94f, -1.18f,  1.32f, -2.46f, -0.69f,  1.64f, -2.14f, -0.38f,  2.37f, -1.41f,  0.35f, -0.07f, -3.85f, -2.09f,  0.24f, -3.54f, -1.77f,  0.97f, -2.81f, -1.04f,  }, // 24
  { -4.98f, -0.65f, -2.67f, -4.67f, -0.34f, -2.35f, -3.93f,  0.40f, -1.62f, -3.99f,  0.34f, -1.67f, -3.67f,  0.66f, -1.36f, -2.94f,  1.39f, -0.63f, -2.46f,  1.87f, -0.14f, -2.14f,  2.19f,  0.17f, -1.41f,  2.92f,  0.91f, -3.85f,  0.48f, -1.54f, -3.54f,  0.79f, -1.22f, -2.81f,  1.52f, -0.49f,  }, // 25
  { -3.22f, -2.67f, -1.64f, -2.90f, -2.35f, -1.33f, -2.17f, -1.62f, -0.59f, -2.23f, -1.67f, -0.65f, -1.91f, -1.36f, -0.34f, -1.18f, -0.63f,  0.40f, -0.69f, -0.14f,  0.88f, -0.38f,  0.17f,  1.20f,  0.35f,  0.91f,  1.93f, -2.09f, -1.54f, -0.51f, -1.77f, -1.22f, -0.20f, -1.04f, -0.49f,  0.53f,  }, // 26
  { -0.82f, -4.60f, -2.83f, -3.02f, -6.80f, -5.04f, -2.20f, -5.98f, -4.21f,  0.61f, -3.17f, -1.40f, -1.59f, -5.37f, -3.61f, -0.77f, -4.54f, -2.78f,  1.30f, -2.47f, -0.71f, -0.90f, -4.68f, -2.91f, -0.07f, -3.85f, -2.09f,  2.57f, -1.21f,  0.55f,  0.36f, -3.42f, -1.65f,  1.19f, -2.59f, -0.83f,  }, // 27
  { -4.60f, -0.27f, -2.28f, -6.80f, -2.47f, -4.49f, -5.98f, -1.64f, -3.66f, -3.17f,  1.16f, -0.85f, -5.37f, -1.04f, -3.05f, -4.54f, -0.21f, -2.23f, -2.47f,  1.86f, -0.16f, -4.68f, -0.35f, -2.36f, -3.85f,  0.48f, -1.54f, -1.21f,  3.12f,  1.10f, -3.42f,  0.91f, -1.10f, -2.59f,  1.74f, -0.28f,  }, // 28
  { -2.83f, -2.28f, -1.26f, -5.04f, -4.49f, -3.46f, -4.21f, -3.66f, -2.64f, -1.40f, -0.85f,  0.17f, -3.61f, -3.05f, -2.03f, -2.78f, -2.23f, -1.21f, -0.71f, -0.16f,  0.86f, -2.91f, -2.36f, -1.34f, -2.09f, -1.54f, -0.51f,  0.55f,  1.10f,  2.13f, -1.65f, -1.10f, -0.08f, -0.83f, -0.28f,  0.75f,  }, // 29
  { -3.02f, -6.80f, -5.04f, -0.50f, -4.28f, -2.52f, -1.88f, -5.66f, -3.90f, -1.59f, -5.37f, -3.61f,  0.93f, -2.85f, -1.09f, -0.45f, -4.23f, -2.47f, -0.90f, -4.68f, -2.91f,  1.62f, -2.16f, -0.39f,  0.24f, -3.54f, -1.77f,  0.36f, -3.42f, -1.65f,  2.88f, -0.90f,  0.87f,  1.50f, -2.28f, -0.51f,  }, // 30
  { -6.80f, -2.47f, -4.49f, -4.28f,  0.05f, -1.97f, -5.66f, -1.33f, -3.35f, -5.37f, -1.04f, -3.05f, -2.85f,  1.48f, -0.53f, -4.23f,  0.10f, -1.91f, -4.68f, -0.35f, -2.36f, -2.16f,  2.17f,  0.16f, -3.54f,  0.79f, -1.22f, -3.42f,  0.91f, -1.10f, -0.90f,  3.44f,  1.42f, -2.28f,  2.05f,  0.04f,  }, // 31
  { -5.04f, -4.49f, -3.46f, -2.52f, -1.97f, -0.94f, -3.90f, -3.35f, -2.32f, -3.61f, -3.05f, -2.03f, -1.09f, -0.53f,  0.49f, -2.47f, -1.91f, -0.89f, -2.91f, -2.36f, -1.34f, -0.39f,  0.16f,  1.18f, -1.77f, -1.22f, -0.20f, -1.65f, -1.10f, -0.08f,  0.87f,  1.42f,  2.44f, -0.51f,  0.04f,  1.06f,  }, // 32
  { -2.20f, -5.98f, -4.21f, -1.88f, -5.66f, -3.90f, -1.15f, -4.93f, -3.16f, -0.77f, -4.54f, -2.78f, -0.45f, -4.23f, -2.47f,  0.28f, -3.50f, -1.73f, -0.07f, -3.85f, -2.09f,  0.24f, -3.54f, -1.77f,  0.97f, -2.81f, -1.04f,  1.19f, -2.59f, -0.83f,  1.50f, -2.28f, -0.51f,  2.24f, -1.54f,  0.22f,  }, // 33
  { -5.98f, -1.64f, -3.66f, -5.66f, -1.33f, -3.35f, -4.93f, -0.60f, -2.61f, -4.54f, -0.21f, -2.23f, -4.23f,  0.10f, -1.91f, -3.50f,  0.83f, -1.18f, -3.85f,  0.48f, -1.54f, -3.54f,  0.79f, -1.22f, -2.81f,  1.52f, -0.49f, -2.59f,  1.74f, -0.28f, -2.28f,  2.05f,  0.04f, -1.54f,  2.79f,  0.77f,  }, // 34
  { -4.21f, -3.66f, -2.64f, -3.90f, -3.35f, -2.32f, -3.16f, -2.61f, -1.59f, -2.78f, -2.23f, -1.21f, -2.47f, -1.91f, -0.89f, -1.73f, -1.18f, -0.16f, -2.09f, -1.54f, -0.51f, -1.77f, -1.22f, -0.20f, -1.04f, -0.49f,  0.53f, -0.83f, -0.28f,  0.75f, -0.51f,  0.04f,  1.06f,  0.22f,  0.77f,  1.80f,  }, // 35
};

int8_t IntScoreMx_Combo[36][36] = {
  {   3,  -1,   1,   1,  -3,  -1,   2,  -2,   0,   1,  -3,  -1,  -1,  -5,  -3,   0,  -4,  -2,   0,  -4,  -2,  -2,  -6,  -4,  -1,  -5,  -3,  -1,  -5,  -3,  -3,  -7,  -5,  -2,  -6,  -4,  }, // 0
  {  -1,   4,   2,  -3,   1,  -1,  -2,   2,   0,  -3,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  -4,   1,  -1,  -6,  -1,  -3,  -5,  -1,  -3,  -5,   0,  -2,  -7,  -2,  -4,  -6,  -2,  -4,  }, // 1
  {   1,   2,   3,  -1,  -1,   0,   0,   0,   1,  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,  -2,  -1,   0,  -4,  -3,  -2,  -3,  -3,  -2,  -3,  -2,  -1,  -5,  -4,  -3,  -4,  -4,  -3,  }, // 2
  {   1,  -3,  -1,   3,   0,   1,   2,  -2,   0,  -1,  -5,  -3,   2,  -2,  -1,   0,  -4,  -2,  -2,  -6,  -4,   0,  -3,  -2,  -1,  -5,  -3,  -3,  -7,  -5,  -1,  -4,  -3,  -2,  -6,  -4,  }, // 3
  {  -3,   1,  -1,   0,   4,   2,  -2,   3,   1,  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  -6,  -1,  -3,  -3,   1,  -1,  -5,   0,  -2,  -7,  -2,  -4,  -4,   0,  -2,  -6,  -1,  -3,  }, // 4
  {  -1,  -1,   0,   1,   2,   3,   0,   1,   2,  -3,  -2,  -1,  -1,   0,   1,  -2,  -1,   0,  -4,  -3,  -2,  -2,  -1,   0,  -3,  -2,  -1,  -5,  -4,  -3,  -3,  -2,  -1,  -4,  -3,  -2,  }, // 5
  {   2,  -2,   0,   2,  -2,   0,   3,  -1,   1,   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,  -1,  -5,  -3,  -1,  -5,  -3,   0,  -4,  -2,  -2,  -6,  -4,  -2,  -6,  -4,  -1,  -5,  -3,  }, // 6
  {  -2,   2,   0,  -2,   3,   1,  -1,   3,   1,  -4,   0,  -2,  -4,   1,  -1,  -3,   1,  -1,  -5,  -1,  -3,  -5,   0,  -2,  -4,   0,  -2,  -6,  -2,  -4,  -6,  -1,  -3,  -5,  -1,  -3,  }, // 7
  {   0,   0,   1,   0,   1,   2,   1,   1,   2,  -2,  -2,  -1,  -2,  -1,   0,  -1,  -1,   0,  -3,  -3,  -2,  -3,  -2,  -1,  -2,  -2,  -1,  -4,  -4,  -3,  -4,  -3,  -2,  -3,  -3,  -2,  }, // 8
  {   1,  -3,  -1,  -1,  -5,  -3,   0,  -4,  -2,   2,  -2,   0,   0,  -4,  -2,   1,  -3,  -1,   1,  -3,  -1,  -1,  -5,  -3,   0,  -4,  -2,   1,  -3,  -1,  -2,  -5,  -4,  -1,  -5,  -3,  }, // 9
  {  -3,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  -2,   3,   1,  -4,   0,  -2,  -3,   1,  -1,  -3,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  -3,   1,  -1,  -5,  -1,  -3,  -5,   0,  -2,  }, // 10
  {  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,   0,   1,   2,  -2,  -2,  -1,  -1,  -1,   0,  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,  -1,  -1,   0,  -4,  -3,  -2,  -3,  -2,  -1,  }, // 11
  {  -1,  -5,  -3,   2,  -2,  -1,   0,  -4,  -2,   0,  -4,  -2,   2,  -1,   0,   1,  -3,  -1,  -1,  -5,  -3,   1,  -2,  -1,   0,  -4,  -2,  -2,  -5,  -4,   1,  -3,  -1,   0,  -4,  -2,  }, // 12
  {  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  -4,   0,  -2,  -1,   3,   1,  -3,   2,   0,  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  -5,  -1,  -3,  -3,   1,  -1,  -4,   0,  -2,  }, // 13
  {  -3,  -2,  -1,  -1,   0,   1,  -2,  -1,   0,  -2,  -2,  -1,   0,   1,   2,  -1,   0,   1,  -3,  -2,  -1,  -1,   0,   1,  -2,  -1,   0,  -4,  -3,  -2,  -1,  -1,   0,  -2,  -2,  -1,  }, // 14
  {   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,   1,  -3,  -1,   1,  -3,  -1,   2,  -2,   0,   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,  -1,  -5,  -3,   0,  -4,  -2,   0,  -3,  -2,  }, // 15
  {  -4,   0,  -2,  -4,   1,  -1,  -3,   1,  -1,  -3,   1,  -1,  -3,   2,   0,  -2,   2,   0,  -4,   0,  -2,  -4,   1,  -1,  -3,   1,  -1,  -5,   0,  -2,  -4,   0,  -2,  -3,   1,  -1,  }, // 16
  {  -2,  -2,  -1,  -2,  -1,   0,  -1,  -1,   0,  -1,  -1,   0,  -1,   0,   1,   0,   0,   1,  -2,  -2,  -1,  -2,  -1,   0,  -1,  -1,   0,  -3,  -2,  -1,  -2,  -2,  -1,  -2,  -1,   0,  }, // 17
  {   0,  -4,  -2,  -2,  -6,  -4,  -1,  -5,  -3,   1,  -3,  -1,  -1,  -5,  -3,   0,  -4,  -2,   3,  -1,   1,   0,  -3,  -2,   1,  -2,  -1,   1,  -2,  -1,  -1,  -5,  -3,   0,  -4,  -2,  }, // 18
  {  -4,   1,  -1,  -6,  -1,  -3,  -5,  -1,  -3,  -3,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  -1,   3,   1,  -3,   1,  -1,  -2,   2,   0,  -2,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  }, // 19
  {  -2,  -1,   0,  -4,  -3,  -2,  -3,  -3,  -2,  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,   1,   1,   2,  -2,  -1,   0,  -1,   0,   1,  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,  }, // 20
  {  -2,  -6,  -4,   0,  -3,  -2,  -1,  -5,  -3,  -1,  -5,  -3,   1,  -2,  -1,   0,  -4,  -2,   0,  -3,  -2,   3,  -1,   1,   2,  -2,   0,  -1,  -5,  -3,   2,  -2,   0,   0,  -4,  -2,  }, // 21
  {  -6,  -1,  -3,  -3,   1,  -1,  -5,   0,  -2,  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  -3,   1,  -1,  -1,   4,   2,  -2,   2,   0,  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  }, // 22
  {  -4,  -3,  -2,  -2,  -1,   0,  -3,  -2,  -1,  -3,  -2,  -1,  -1,   0,   1,  -2,  -1,   0,  -2,  -1,   0,   1,   2,   3,   0,   0,   1,  -3,  -2,  -1,   0,   0,   1,  -2,  -1,   0,  }, // 23
  {  -1,  -5,  -3,  -1,  -5,  -3,   0,  -4,  -2,   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,   1,  -2,  -1,   2,  -2,   0,   2,  -1,   0,   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,  }, // 24
  {  -5,  -1,  -3,  -5,   0,  -2,  -4,   0,  -2,  -4,   0,  -2,  -4,   1,  -1,  -3,   1,  -1,  -2,   2,   0,  -2,   2,   0,  -1,   3,   1,  -4,   0,  -2,  -4,   1,  -1,  -3,   2,   0,  }, // 25
  {  -3,  -3,  -2,  -3,  -2,  -1,  -2,  -2,  -1,  -2,  -2,  -1,  -2,  -1,   0,  -1,  -1,   0,  -1,   0,   1,   0,   0,   1,   0,   1,   2,  -2,  -2,  -1,  -2,  -1,   0,  -1,   0,   1,  }, // 26
  {  -1,  -5,  -3,  -3,  -7,  -5,  -2,  -6,  -4,   1,  -3,  -1,  -2,  -5,  -4,  -1,  -5,  -3,   1,  -2,  -1,  -1,  -5,  -3,   0,  -4,  -2,   3,  -1,   1,   0,  -3,  -2,   1,  -3,  -1,  }, // 27
  {  -5,   0,  -2,  -7,  -2,  -4,  -6,  -2,  -4,  -3,   1,  -1,  -5,  -1,  -3,  -5,   0,  -2,  -2,   2,   0,  -5,   0,  -2,  -4,   0,  -2,  -1,   3,   1,  -3,   1,  -1,  -3,   2,   0,  }, // 28
  {  -3,  -2,  -1,  -5,  -4,  -3,  -4,  -4,  -3,  -1,  -1,   0,  -4,  -3,  -2,  -3,  -2,  -1,  -1,   0,   1,  -3,  -2,  -1,  -2,  -2,  -1,   1,   1,   2,  -2,  -1,   0,  -1,   0,   1,  }, // 29
  {  -3,  -7,  -5,  -1,  -4,  -3,  -2,  -6,  -4,  -2,  -5,  -4,   1,  -3,  -1,   0,  -4,  -2,  -1,  -5,  -3,   2,  -2,   0,   0,  -4,  -2,   0,  -3,  -2,   3,  -1,   1,   2,  -2,  -1,  }, // 30
  {  -7,  -2,  -4,  -4,   0,  -2,  -6,  -1,  -3,  -5,  -1,  -3,  -3,   1,  -1,  -4,   0,  -2,  -5,   0,  -2,  -2,   2,   0,  -4,   1,  -1,  -3,   1,  -1,  -1,   3,   1,  -2,   2,   0,  }, // 31
  {  -5,  -4,  -3,  -3,  -2,  -1,  -4,  -3,  -2,  -4,  -3,  -2,  -1,  -1,   0,  -2,  -2,  -1,  -3,  -2,  -1,   0,   0,   1,  -2,  -1,   0,  -2,  -1,   0,   1,   1,   2,  -1,   0,   1,  }, // 32
  {  -2,  -6,  -4,  -2,  -6,  -4,  -1,  -5,  -3,  -1,  -5,  -3,   0,  -4,  -2,   0,  -3,  -2,   0,  -4,  -2,   0,  -4,  -2,   1,  -3,  -1,   1,  -3,  -1,   2,  -2,  -1,   2,  -2,   0,  }, // 33
  {  -6,  -2,  -4,  -6,  -1,  -3,  -5,  -1,  -3,  -5,   0,  -2,  -4,   0,  -2,  -3,   1,  -1,  -4,   0,  -2,  -4,   1,  -1,  -3,   2,   0,  -3,   2,   0,  -2,   2,   0,  -2,   3,   1,  }, // 34
  {  -4,  -4,  -3,  -4,  -3,  -2,  -3,  -3,  -2,  -3,  -2,  -1,  -2,  -2,  -1,  -2,  -1,   0,  -2,  -2,  -1,  -2,  -1,   0,  -1,   0,   1,  -1,   0,   1,  -1,   0,   1,   0,   1,   2,  }, // 35
};