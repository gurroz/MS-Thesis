#!/bin/sh

DISTRIBUTION=0 #  0: Unifor, 1: Normal
LIST_ORDER=3 #  0: RAND_U, 1: ASC, 2: DESC 3: NORM_RAND
UNIQUE_ELEMENT=0 #  0.0 - 1.0
UNIQUE_LIST=0 #  0.0 - 1.0

# ./main array_length distribution uniqueness  list_order

## SEGMENTED
#echo "SEGMENTED"
#
## ./main 16 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 8
## ./main 32 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 8
## ./main 64 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 8
#./main 128 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 64
#./main 256 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 64
#./main 512 $DISTRIBUTION 0.0 $LIST_ORDER 0.0 64
#
## ./main 16 $DISTRIBUTION 0.25 $LIST_ORDER 0.25 8
## ./main 32  $DISTRIBUTION 0.25 $LIST_ORDER 0.25 8
## ./main 64  $DISTRIBUTION 0.25 $LIST_ORDER 0.25 8
#./main 128 $DISTRIBUTION 0.25 $LIST_ORDER 0.25 64
#./main 256 $DISTRIBUTION 0.25 $LIST_ORDER 0.25 64
#./main 512  $DISTRIBUTION 0.25 $LIST_ORDER 0.25 64
#
## ./main 16 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 8
## ./main 32 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 8
## ./main 64 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 8
#./main 128 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 64
#./main 256 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 64
#./main 512 $DISTRIBUTION 0.5 $LIST_ORDER 0.5 64
#
## ./main 16 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 8
## ./main 32 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 8
## ./main 64 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 8
#./main 128 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 64
#./main 256 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 64
#./main 512 $DISTRIBUTION 0.75 $LIST_ORDER 0.75 64
#
## ./main 16 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 8
## ./main 32 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 8
## ./main 64 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 8
#./main 128 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 64
#./main 256 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 64
#./main 512 $DISTRIBUTION  1.0 $LIST_ORDER 1.0 64


### SORTS
#echo "SORTS 2"
#
#./main 16 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#./main 32 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#./main 64 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#./main 128 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#./main 256 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#./main 512 $DISTRIBUTION 0.0 $LIST_ORDER 1.0
#
#./main 16 $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#./main 32  $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#./main 64  $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#./main 128 $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#./main 256 $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#./main 512  $DISTRIBUTION 0.25 $LIST_ORDER 1.0
#
#./main 16 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#./main 32 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#./main 64 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#./main 128 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#./main 256 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#./main 512 $DISTRIBUTION 0.5 $LIST_ORDER 1.0
#
#./main 16 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#./main 32 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#./main 64 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#./main 128 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#./main 256 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#./main 512 $DISTRIBUTION 0.75 $LIST_ORDER 1.0
#
#./main 16 $DISTRIBUTION  1.0 $LIST_ORDER 1.0
#./main 32 $DISTRIBUTION  1.0 $LIST_ORDER 1.0
#./main 64 $DISTRIBUTION  1.0 $LIST_ORDER 1.0
#./main 128 $DISTRIBUTION  1.0 $LIST_ORDER 1.0
#./main 256 $DISTRIBUTION  1.0 $LIST_ORDER 1.0
#./main 512 $DISTRIBUTION  1.0 $LIST_ORDER 1.0

## SORTS
echo "Insertion vs Merge"

./main 16 $DISTRIBUTION 1.0 1 1.0 1.0 8
./main 32 $DISTRIBUTION 1.0 1 1.0 1.0 8
./main 64 $DISTRIBUTION 1.0 1 1.0 1.0 8
./main 128 $DISTRIBUTION 1.0 1 1.0 1.0 8
./main 256 $DISTRIBUTION 1.0 1 1.0 1.0 8
./main 512 $DISTRIBUTION 1.0 1 1.0 1.0 8

./main 16 $DISTRIBUTION 1.0 2 1.0 1.0 8
./main 32 $DISTRIBUTION 1.0 2 1.0 1.0 8
./main 64 $DISTRIBUTION 1.0 2 1.0 1.0 8
./main 128 $DISTRIBUTION 1.0 2 1.0 1.0 8
./main 256 $DISTRIBUTION 1.0 2 1.0 1.0 8
./main 512 $DISTRIBUTION 1.0 2 1.0 1.0 8

./main 16 $DISTRIBUTION 1.0 3 1.0 1.0 8
./main 32 $DISTRIBUTION 1.0 3 1.0 1.0 8
./main 64 $DISTRIBUTION 1.0 3 1.0 1.0 8
./main 128 $DISTRIBUTION 1.0 3 1.0 1.0 8
./main 256 $DISTRIBUTION 1.0 3 1.0 1.0 8
./main 512 $DISTRIBUTION 1.0 3 1.0 1.0 8

## OPTIMIZED SORT DIST RAND NORMAL
#echo "OPTIMIZED SORT DIST RAND NORMAL"
#
#./main 16 0 0.0 3 1.0
#./main 32 0 0.0 3 1.0
#./main 64 0 0.0 3 1.0
#./main 128 0 0.0 3 1.0
#./main 256 0 0.0 3 1.0
#./main 512 0 0.0 3 1.0
#
#./main 16 0 0.25 3 1.0
#./main 32 0 0.25 3 1.0
#./main 64 0 0.25 3 1.0
#./main 128 0 0.25 3 1.0
#./main 256 0 0.25 3 1.0
#./main 512 0 0.25 3 1.0
#
#./main 16 0 0.5 3 1.0
#./main 32 0 0.5 3 1.0
#./main 64 0 0.5 3 1.0
#./main 128 0 0.5 3 1.0
#./main 256 0 0.5 3 1.0
#./main 512 0 0.5 3 1.0
#
#./main 16 0 0.75 3 1.0
#./main 32 0 0.75 3 1.0
#./main 64 0 0.75 3 1.0
#./main 128 0 0.75 3 1.0
#./main 256 0 0.75 3 1.0
#./main 512 0 0.75 3 1.0
#
#./main 16 0 1.0 3 1.0
#./main 32 0 1.0 3 1.0
#./main 64 0 1.0 3 1.0
#./main 128 0 1.0 3 1.0
#./main 256 0 1.0 3 1.0
#./main 512 0 1.0 3 1.0

# # # UNIFORM DIST RAND
# echo "UNIFORM DIST RAND NORMAL"

# ./main 16 0 0.0 3
# ./main 32 0 0.0 3
# ./main 64 0 0.0 3
# ./main 128 0 0.0 3
# ./main 256 0 0.0 3
# ./main 512 0 0.0 3

# ./main 16 0 0.25 3
# ./main 32 0 0.25 3
# ./main 64 0 0.25 3
# ./main 128 0 0.25 3
# ./main 256 0 0.25 3
# ./main 512 0 0.25 3

# ./main 16 0 0.5 3
# ./main 32 0 0.5 3
# ./main 64 0 0.5 3
# ./main 128 0 0.5 3
# ./main 256 0 0.5 3
# ./main 512 0 0.5 3

# ./main 16 0 0.75 3
# ./main 32 0 0.75 3
# ./main 64 0 0.75 3
# ./main 128 0 0.75 3
# ./main 256 0 0.75 3
# ./main 512 0 0.75 3

# ./main 16 0 1.0 3
# ./main 32 0 1.0 3
# ./main 64 0 1.0 3
# ./main 128 0 1.0 3
# ./main 256 0 1.0 3
# ./main 512 0 1.0 3

# # UNIFORM DIST RAND
# echo "UNIFORM DIST RAND"

# ./main 16 0 0.0 0
# ./main 32 0 0.0 0
# ./main 64 0 0.0 0
# ./main 128 0 0.0 0
# ./main 256 0 0.0 0
# ./main 512 0 0.0 0

# ./main 16 0 0.25 0
# ./main 32 0 0.25 0
# ./main 64 0 0.25 0
# ./main 128 0 0.25 0
# ./main 256 0 0.25 0
# ./main 512 0 0.25 0

# ./main 16 0 0.5 0
# ./main 32 0 0.5 0
# ./main 64 0 0.5 0
# ./main 128 0 0.5 0
# ./main 256 0 0.5 0
# ./main 512 0 0.5 0

# ./main 16 0 0.75 0
# ./main 32 0 0.75 0
# ./main 64 0 0.75 0
# ./main 128 0 0.75 0
# ./main 256 0 0.75 0
# ./main 512 0 0.75 0

# ./main 16 0 1.0 0
# ./main 32 0 1.0 0
# ./main 64 0 1.0 0
# ./main 128 0 1.0 0
# ./main 256 0 1.0 0
# ./main 512 0 1.0 0


# # NORMAL DIST RAND
# echo "NORMAL DIST RAND"

# ./main 16 1 0.0 0
# ./main 32 1 0.0 0
# ./main 64 1 0.0 0
# ./main 128 1 0.0 0
# ./main 256 1 0.0 0
# ./main 512 1 0.0 0

# ./main 16 1 0.25 0
# ./main 32 1 0.25 0
# ./main 64 1 0.25 0
# ./main 128 1 0.25 0
# ./main 256 1 0.25 0
# ./main 512 1 0.25 0

# ./main 16 1 0.5 0
# ./main 32 1 0.5 0
# ./main 64 1 0.5 0
# ./main 128 1 0.5 0
# ./main 256 1 0.5 0
# ./main 512 1 0.5 0

# ./main 16 1 0.75 0
# ./main 32 1 0.75 0
# ./main 64 1 0.75 0
# ./main 128 1 0.75 0
# ./main 256 1 0.75 0
# ./main 512 1 0.75 0

# ./main 16 1 1.0 0
# ./main 32 1 1.0 0
# ./main 64 1 1.0 0
# ./main 128 1 1.0 0
# ./main 256 1 1.0 0
# ./main 512 1 1.0 0


# # UNIFORM DIST AS1
# echo "UNIFORM DIST AS1"
# ./main 16 0 0.0 1
# ./main 32 0 0.0 1
# ./main 64 0 0.0 1
# ./main 128 0 0.0 1
# ./main 256 0 0.0 1
# ./main 512 0 0.0 1

# ./main 16 0 0.25 1
# ./main 32 0 0.25 1
# ./main 64 0 0.25 1
# ./main 128 0 0.25 1
# ./main 256 0 0.25 1
# ./main 512 0 0.25 1

# ./main 16 0 0.5 1
# ./main 32 0 0.5 1
# ./main 64 0 0.5 1
# ./main 128 0 0.5 1
# ./main 256 0 0.5 1
# ./main 512 0 0.5 1

# ./main 16 0 0.75 1
# ./main 32 0 0.75 1
# ./main 64 0 0.75 1
# ./main 128 0 0.75 1
# ./main 256 0 0.75 1
# ./main 512 0 0.75 1

# ./main 16 0 1.0 1
# ./main 32 0 1.0 1
# ./main 64 0 1.0 1
# ./main 128 0 1.0 1
# ./main 256 0 1.0 1
# ./main 512 0 1.0 1


# # NORMAL DIST ASC
# echo "NORMAL DIST ASC"

# ./main 16 1 0.0 1
# ./main 32 1 0.0 1
# ./main 64 1 0.0 1
# ./main 128 1 0.0 1
# ./main 256 1 0.0 1
# ./main 512 1 0.0 1

# ./main 16 1 0.25 1
# ./main 32 1 0.25 1
# ./main 64 1 0.25 1
# ./main 128 1 0.25 1
# ./main 256 1 0.25 1
# ./main 512 1 0.25 1

# ./main 16 1 0.5 1
# ./main 32 1 0.5 1
# ./main 64 1 0.5 1
# ./main 128 1 0.5 1
# ./main 256 1 0.5 1
# ./main 512 1 0.5 1

# ./main 16 1 0.75 1
# ./main 32 1 0.75 1
# ./main 64 1 0.75 1
# ./main 128 1 0.75 1
# ./main 256 1 0.75 1
# ./main 512 1 0.75 1

# ./main 16 1 1.0 1
# ./main 32 1 1.0 1
# ./main 64 1 1.0 1
# ./main 128 1 1.0 1
# ./main 256 1 1.0 1
# ./main 512 1 1.0 1

# # UNIFORM DIST DESC
# echo "UNIFORM DIST DESC"

# ./main 16 0 0.0 1
# ./main 32 0 0.0 1
# ./main 64 0 0.0 1
# ./main 128 0 0.0 1
# ./main 256 0 0.0 1
# ./main 512 0 0.0 1

# ./main 16 0 0.25 1
# ./main 32 0 0.25 1
# ./main 64 0 0.25 1
# ./main 128 0 0.25 1
# ./main 256 0 0.25 1
# ./main 512 0 0.25 1

# ./main 16 0 0.5 1
# ./main 32 0 0.5 1
# ./main 64 0 0.5 1
# ./main 128 0 0.5 1
# ./main 256 0 0.5 1
# ./main 512 0 0.5 1

# ./main 16 0 0.75 1
# ./main 32 0 0.75 1
# ./main 64 0 0.75 1
# ./main 128 0 0.75 1
# ./main 256 0 0.75 1
# ./main 512 0 0.75 1

# ./main 16 0 1.0 1
# ./main 32 0 1.0 1
# ./main 64 0 1.0 1
# ./main 128 0 1.0 1
# ./main 256 0 1.0 1
# ./main 512 0 1.0 1


# # NORMAL DIST DESC
# echo "NORMAL DIST DESC"

# ./main 16 1 0.0 2
# ./main 32 1 0.0 2
# ./main 64 1 0.0 2
# ./main 128 1 0.0 2
# ./main 256 1 0.0 2
# ./main 512 1 0.0 2

# ./main 16 1 0.25 2
# ./main 32 1 0.25 2
# ./main 64 1 0.25 2
# ./main 128 1 0.25 2
# ./main 256 1 0.25 2
# ./main 512 1 0.25 2

# ./main 16 1 0.5 2
# ./main 32 1 0.5 2
# ./main 64 1 0.5 2
# ./main 128 1 0.5 2
# ./main 256 1 0.5 2
# ./main 512 1 0.5 2

# ./main 16 1 0.75 2
# ./main 32 1 0.75 2
# ./main 64 1 0.75 2
# ./main 128 1 0.75 2
# ./main 256 1 0.75 2
# ./main 512 1 0.75 2

# ./main 16 1 1.0 2
# ./main 32 1 1.0 2
# ./main 64 1 1.0 2
# ./main 128 1 1.0 2
# ./main 256 1 1.0 2
# ./main 512 1 1.0 2

