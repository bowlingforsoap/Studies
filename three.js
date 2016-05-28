Transform Matrix (TM) is a 4x4 matrix used to TRaSh the coordinates or whatever.
By multiplying a TM by a vector we get a new transformed vector (essentially, a dot prodoct is computed for every row of the matrix with the vector)

(x, y, z, 1) - a point
(x, y, z, 0) - a vector
Is also good for operations on vectors (e.g. can show the illigal operations, which do not make sense in general, like adding 2 points [gives 2, which is neither 1, nor 0 in a 4th component -> illigal])

Identity matrix (Id) is a default setting for a matrix in 3.js (main diagonal values are 1s, all the others are 0s)
If you multiply a vector by an Id you get the same vector
To make a matrix an Id, call .identity() on the variable
