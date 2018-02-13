#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

SEXP my_match_C(SEXP pos, SEXP Rvector)
{

pos      = coerceVector(pos, REALSXP);
Rvector  = coerceVector(Rvector, REALSXP);

long int size1;
long int size2;

double *vec1 = REAL(pos);
double *vec2 = REAL(Rvector);

size1       = length(pos);
size2       = length(Rvector);

SEXP matchIDS    = R_NilValue;
PROTECT(matchIDS = allocVector(INTSXP, size1));
int *mmm         = INTEGER(matchIDS);

// Init match matchIDS wit NA values
for(long int x=0; x<size1;x++){
mmm[x] = R_NaReal;
}

long int m       = 0;

  for (long int j=0; j < size2; j++){
	
	if(vec1[m]==vec2[j]){         
	   mmm[m] = j+1;
	   m = m + 1;
	   if(m == size1){
	   break;
	   }
	j = j - 1;	   			
       	}

	if(vec1[m]<vec2[j]){
	  m = m + 1;
	  if(m == size1){
	   break;
	  }
	j = j - 1;  	        
	}
	
  }

UNPROTECT(1);
return matchIDS;


}

// returns the id in Rvector of bigger value than pos

SEXP whichbigger_C(SEXP pos, SEXP Rvector)
{

PROTECT(pos);

  pos      = coerceVector(pos, INTSXP);
  Rvector  = coerceVector(Rvector, INTSXP);

int size1;
int size2;
int *vec1 = INTEGER(pos);
int *vec2 = INTEGER(Rvector);

size1       = length(pos);
size2       = length(Rvector);

int treffer = 0;

for(int j=0; j < size2; j++) {

	if(vec1[0]<=vec2[j]){          
	   INTEGER(pos)[0] = j + 1;
           treffer = 1;
           break;
	}
}

if(treffer==0){
  INTEGER(pos)[0] = 1;
}


UNPROTECT(1);
return pos;

}




