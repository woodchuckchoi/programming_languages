[1,2,3] ++ [3,4,5]

[1,2,3] -- [1,5]

"foo" <> "bar"	# string concatenation

true and true

false and is_atom(:example)

and or not

or / and operations always execute the left side first and only when it is not enough to determine the status, execute the right side

|| && !

right 1 == 1.0
wrong 1 === 1.0

sorting order
number < atom < reference < function < port < pid < tuple < map < list < bitstring
