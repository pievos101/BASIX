\name{BASIX.combnapply}

\docType{methods}
\alias{BASIX.combnapply}


\title{Combine-Apply}


\description{

This function applies a specific calculation, defined by the user, to all pairs of 
entries of a vector.

}

\usage{

BASIX.combnapply(vec, mode='*')

}

\arguments{

  \item{vec}{vector}
  \item{mode}{\code{*,-,/,+ or ==}}
 
}  

\details{
\code{BASIX.combnapply} returns values for each pair-combination.
}

\examples{
vec  <- c(1,3,5,7,9,10)
BASIX.combnapply(vec)

}

\author{Bastian Pfeifer}

\keyword{methods}
