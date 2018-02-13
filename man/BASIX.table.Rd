\name{BASIX.table}

\docType{methods}
\alias{BASIX.table}


\title{

Count Tabulation of Matrices

}


\description{

\code{BASIX.table} computes the counts of unique rows of a matrix.

}

\usage{

BASIX.table(matrix)

}

\arguments{

  \item{matrix}{a matrix}
  
}  

\details{

This function can be applied to numeric as well as character matrices.

}


\examples{

mat <- matrix(0,3,3)
mat[1,1] <- 1

BASIX.table(mat)

}

\author{Bastian Pfeifer}

\keyword{methods}
