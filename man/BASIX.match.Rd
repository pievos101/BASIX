\name{BASIX.match}

\docType{methods}
\alias{BASIX.match}


\title{

Value Matching for sorted vectors.

}


\description{
The function returns a vector of the positions of (first) matches of
its first argument in its second.
}

\usage{

BASIX.match(elements,vec)

}

\arguments{

  \item{elements}{values to be matched}
  \item{vec}{the values to be matched against}

}  

\details{

\code{BASIX.match} stops at the first match and continues with the next 
element of \code{elements} starting from the match position in \code{vec}. 

The native R solution would be:

\code{match(elements,vec)}

}


\examples{

elements <- c(1,2,10)
vec      <- c(2,3,4,10,11)

BASIX.match(elements,vec)

}

\author{Bastian Pfeifer}

\keyword{methods}
