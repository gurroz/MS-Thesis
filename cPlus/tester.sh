#!/bin/sh

#DISTRIBUTION 0 // 0: Unifor, 1: Normal
#LIST_ORDER 0 // 0: RAND, 1: ASC, 2: DESC

# ./main array_length distribution uniqueness  list_order

# # SORTS
# echo "SORTS"
./main 16 0 1.0 0
sleep 1
./main 32 0 1.0 0
sleep 1
./main 64 0 1.0 0
sleep 1
./main 128 0 1.0 0
sleep 1
./main 256 0 1.0 0
sleep 1
./main 512 0 1.0 0
sleep 1
./main 16 0 1.0 1
sleep 1
./main 32 0 1.0 1
sleep 1
./main 64 0 1.0 1
sleep 1
./main 128 0 1.0 1
sleep 1
./main 256 0 1.0 1
sleep 1
./main 512 0 1.0 1
sleep 1

./main 16 0 1.0 2
sleep 1
./main 32 0 1.0 2
sleep 1
./main 64 0 1.0 2
sleep 1
./main 128 0 1.0 2
sleep 1
./main 256 0 1.0 2
sleep 1
./main 512 0 1.0 2
sleep 1


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

