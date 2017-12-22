// For FastLED
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 100 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB
#define LETTER_SIZE 3

/*
	Alphabet Mapping
*/


int x = 0;

int H[LETTER_SIZE] = {x++,x++,x++};
int G[LETTER_SIZE] = {x++,x++,x++};
int F[LETTER_SIZE] = {x++,x++,x++};
int E[LETTER_SIZE] = {x++,x++,x++};
int D[LETTER_SIZE] = {x++,x++,x++};
int C[LETTER_SIZE] = {x++,x++,x++};
int B[LETTER_SIZE] = {x++,x++,x++};
int A[LETTER_SIZE] = {x++,x++,x++};

int skip3_1[LETTER_SIZE] = {x++,x++,x++};
int skip3_2[LETTER_SIZE] = {x++,x++,x++};
int skip3_3[LETTER_SIZE] = {x++,x++,x++};

int I[LETTER_SIZE] = {x++,x++,x++};
int J[LETTER_SIZE] = {x++,x++,x++};
int K[LETTER_SIZE] = {x++,x++,x++};
int L[LETTER_SIZE] = {x++,x++,x++};
int M[LETTER_SIZE] = {x++,x++,x++};
int N[LETTER_SIZE] = {x++,x++,x++};
int O[LETTER_SIZE] = {x++,x++,x++};
int P[LETTER_SIZE] = {x++,x++,x++};
int Q[LETTER_SIZE] = {x++,x++,x++};

int skip3_4[LETTER_SIZE] = {x++,x++,x++};
int skip3_5[LETTER_SIZE] = {x++,x++,x++};
int skip3_6[LETTER_SIZE] = {x++,x++,x++};

int Z[LETTER_SIZE] = {x++,x++,x++};
int Y[LETTER_SIZE] = {x++,x++,x++};
int X[LETTER_SIZE] = {x++,x++,x++};
int W[LETTER_SIZE] = {x++,x++,x++};
int V[LETTER_SIZE] = {x++,x++,x++};
int U[LETTER_SIZE] = {x++,x++,x++};
int T[LETTER_SIZE] = {x++,x++,x++};
int S[LETTER_SIZE] = {x++,x++,x++};
int R[LETTER_SIZE] = {x++,x++,x++};

int ALPHA[26] = {
	A,B,C,D,E,F,G,H,
	I,J,K,L,M,N,O,P,Q,
	R,S,T,U,V,W,X,Y,Z
};


uint8_t getIndex(char c) {
  return (toLowerCase(c) - 'a');
}

