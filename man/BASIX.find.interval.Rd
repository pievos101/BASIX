\name{BASIX.find.interval}

\docType{methods}
\alias{BASIX.find.interval}


\title{Positions of elements in a defined region}


\description{
This function returns the positions of elements which are in a defined region.
}

\usage{

BASIX.find.interval(vec,from,to,start=1)

}

\arguments{

  \item{vec}{base vector}
  \item{from}{left side}
  \item{to}{right side}
  \item{start}{the start position}
 
}  

\details{
The function returns the position of the elements in vector \code{vec}, \cr 
which are in a specific interval, defined by \code{from} and \code{to}, \cr
starting from position \code{start}.

The native R solution would be:

\code{ X  <- (vec >= from) & (vec <= to) } \cr
\code{ids <- which(X)}

or the function \code{findInterval()}, which
is just a little bit slower than 
\code{BASIX.interval}

}

\examples{
vec  <- c(1,3,5,7,9,10)
from <- 5
to   <- 8
BASIX.find.interval(vec,from,to,1)
}

\author{Bastian Pfeifer}

\keyword{methods}
