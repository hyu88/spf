// Copyright (c) 2014 Osamu Hirose
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"util.h"
#define LIMIT 256

int writetraj(char *file, const double ***Xyall, const int *Kall, const int *imsize, const int *trsize, const int cut){
   
  int k,t,K,L,M,N,A,B,C,T,off=0,p,P=3;
  int buf[8]; float xy[4];
  FILE *fp  = fopen(file,"wb");

  L=imsize[0];M=imsize[1];N=imsize[2];T=imsize[3];
  A=trsize[0];B=trsize[1];C=trsize[2];

  buf[0]=L;buf[1]=M;buf[2]=N;buf[3]=T;
  buf[4]=A;buf[5]=B;buf[6]=C;buf[7]=cut; fwrite(buf,sizeof(int),8,fp);  

  for(t=0;t<T;t++){K=Kall[t];buf[0]=t;buf[1]=K;
    fwrite(buf,sizeof(int),2,fp);
    for(k=0;k<K;k++){
      for(p=0;p<P+1;p++)xy[p]=(float)Xyall[t][k][p];
      fwrite(xy, sizeof(float),4,fp);
    }
    off+=K;
  }
    
  fclose(fp);

  return 0;
}

int progress(const int n, const int N, const int times, const int w, const double realtime, const double cputime) {
  int i,c; double r;

  if(n%(1+N/times)!=0){r=(double)(n+1)/N;c=r*w;
    printf("  %3d%% [", (int)(r*100));
    for(i=0;i<c;i++) printf("=");
    for(i=c;i<w;i++) printf(" ");
    printf("]\n  Time: %d (sec)   CPU Time: %.2f (sec)",(int)realtime,cputime);
    if(n<N-1)printf("\n\033[F\033[J\033[F\033[J");
    else     printf("\n\n");
  }

  return 0;
}
