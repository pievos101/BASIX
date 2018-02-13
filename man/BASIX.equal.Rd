\name{BASIX.equal}

\docType{methods}
\alias{BASIX.equal}


\title{Test if two vectors are equal}


\description{
This function checks if two vectors are equal, by comparing each cell 
and quits when the first mismatch occurs.
}

\usage{

BASIX.equal(a,b)

}

\arguments{

  \item{a}{first vector}
  \item{b}{second vector}

}  

\details{

Native R functions compare every entry of the entired vectors, \cr  

The R solution would be: \cr

\code{all(a==b)} \cr

The function can be applied to numeric as well as character vectors

}


\examples{

a <- 1:10
b <- a
b[2] <- 9
BASIX.equal(a,b)

}

\author{Bastian Pfeifer}

\keyword{methods}
