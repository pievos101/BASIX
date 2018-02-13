\name{BASIX.unique}

\docType{methods}
\alias{BASIX.unique}


\title{

Extract unique rows of a matrix

}


\description{

\code{BASIX.unique} returns a matrix with duplicate rows removed.
The unique rows ids will be saved as rownames.

}

\usage{

BASIX.unique(matrix)

}

\arguments{

  \item{matrix}{a matrix}
  
}  

\details{

\code{BASIX.unique} 
is a version of \code{unique} specialized on matrices. \cr

The native R solution would be: \cr
\code{unique(matrix)} \cr

This function can be applied to numeric as well as character vectors.

}


\examples{

mat <- matrix(0,3,3)
mat[1,1] <- 1

BASIX.unique(mat)

}

\author{Bastian Pfeifer}

\keyword{methods}
