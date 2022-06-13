#include <stdlib.h>
#include <stdio.h>
#include <R.h>
#include <Rinternals.h>

// in case of numeric vectors
extern SEXP Ccompare(SEXP Rvector1, SEXP Rvector2)
{

SEXP val        = R_NilValue;
PROTECT(val     = Rf_allocVector(INTSXP,1));
INTEGER(val)[0] = 1;

 Rvector1 = coerceVector(Rvector1, REALSXP);
 PROTECT(Rvector1);
 Rvector2 = coerceVector(Rvector2, REALSXP);
 PROTECT(Rvector2);
 
 const double *vec1 = REAL(Rvector1);
 const double *vec2 = REAL(Rvector2);

long int size;
size               = length(Rvector1);
for(long int i=0 ; i < size; i++) {

	if(vec1[i]!=vec2[i]){          
	   INTEGER(val)[0] = 0;
           break;
	}
}

UNPROTECT(3);
return val;

}

// in case of character vectors
extern SEXP Ccompare2(SEXP Rvector1, SEXP Rvector2)
{

SEXP val        = R_NilValue;
PROTECT(val     = Rf_allocVector(INTSXP,1));
INTEGER(val)[0] = 1;

 const char *vec1;
 const char *vec2;

long int size;
size               = length(Rvector1);
for(long int i=0 ; i < size; i++) {

  vec1 = CHAR(STRING_ELT(Rvector1,i));
  vec2 = CHAR(STRING_ELT(Rvector2,i));

          if(strcmp(vec1,vec2)){          
	   INTEGER(val)[0] = 0;
           break;
	  }
}

UNPROTECT(1);
return val;


}

