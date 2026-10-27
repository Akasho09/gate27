# 

## Types of Matrix 

> Symmetric: A^T=A
- Skew-symmetric: A^T=-A
    - if A is skew-symmetric and n is odd, then |A|=0.
- Singular: det(A)=0
- Non-singular: det(A)!=0
- Idempotent: A^2=A
    => A - A^2 = 0 
>    => A(A-I)=0 => lamda( eigen values ) = 0 , 1
- Involutory: A^2=I
- Nilpotent: A^k=0 for some positive integer k
    - All eigen values are zero.
> Orthogonal: A^T.A=I
    => A^T = A^-1.
    => if A is orthogonal, then |A|=1.


## Properties :
1. (AB)C=A(BC)

2. (AB)^T = B^T . A^T

3. For any square matrix \(A\):
> A =  (A+A^T) / 2 + (A-A^T) / 2

4. (AB)^-1=B^-1 . A^-1

##  Trace 
is the sum of the diagonal elements of a square matrix.

## Rank :
-  The rank of a matrix is the maximum number of linearly independent rows or columns.
> Equivalent definition: rank is the order of the largest nonzero minor.
- For an  m * n matrix,
rank(A) = min(m,n)
- det A !=0 => rank = n

### PROPERTIES :
1. Maximum rank	     :   rank(A) <= min(m,n)
2. Product upper bound	 : rank(AB) = min (rank(A), rank(B))
3. rank(A^T)=rank(A)


## Eigenvalues and eigenvectors

1. Characteristic equation
For a square matrix \(A\), the eigenvalues satisfy
> det( A-lambda.I ) = 0
An eigenvector X!=0 satisfies
- if matrix and its eigenvector `direction` is given use below:
    - AX=lambda.X. 
> A- (lambda I) X = 0 
- its characteristic equation is
> lambda^2-(a+d)lambda+(ad-bc)=0
- Therefore,
    - lambda_1 + lambda_2={tr}(A)
    - lambda_1 * lambda_2= det(A)

> Eigen values of (A^n) = (Eigen values of A)^n

2. if eigen values of A are 1,2,3 then eigen of 
    1. A+I will be 1+1,2+1,3+1.
    2. A^n will ne 1^n , 2^n ...

3. For a upper triangular matrix , eigen values are Diagonal elements, including repetitions.

4. A matrix is diagonalizable if it has n `linearly independent eigenvectors`. 
- `Distinct eigenvalues` always have linearly independent corresponding eigenvectors, but repeated eigenvalues require further checking.

## Determenenet
- 3*3 matrix =>
> |A|=a(ei-fh)-b(di-fg)+c(dh-eg)
- expand along row or col with + , - , + 

2. |K.A| = K^n . |A|

3. |A^T|=|A|.

