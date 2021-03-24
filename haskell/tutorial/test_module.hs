-- Tutorial Module

module Tutorial
where

import Data.Char
import Data.Maybe
import Prelude hiding (map, filter, foldr, foldl)

-- returns the number that has a higher value
--
max :: Ord a => a -> a -> a
max x y | x >= y    = x
        | otherwise = y

-- returns whether the input value is positive, 0, or negative
--
signum :: (Ord a, Num a) => a -> Int
signum x  | x <  0    = -1
          | x == 0    = 0
          | otherwise = 1

circleArea :: Floating a => a -> a
circleArea radius = pi * radius * radius

circleArea' :: Floating a => a -> a             -- Float and Double
circleArea' diameter = pi * radius * radius
        where
                radius = diameter / 2.0         -- local binding

addMul :: Num a => a -> a -> (a, a)
addMul x y = (x + y, x * y)                     -- use fst, snd to decompose

-- fst and snd behave as polymorphic functions
-- fst :: (a, b) -> a
-- fst (x, y) = x
-- snd :: (a, b) -> b
-- snd (x, y) = y


-- -- origin of the coordinate system
-- -- 
-- origin :: Point
-- origin = (0, 0)

-- -- move a given point to the right
-- --
-- moveRight :: Point -> Int -> Point
-- moveRight (x, y) distance = (x + distance, y)

-- -- move a given point to upwards
-- --
-- moveUp :: Point -> Int -> Point
-- moveUp (x, y) distance = (x, y + distance)

-- we represent colours by strings
--
-- type Colour = String

-- new name for the type of colour points
--
type ColourPoint = (Int, Int, Colour)

-- origin of the coordinate system in a given colour
--
origin :: Colour -> ColourPoint
origin colour = (0, 0, colour)

-- move a colour point vertically and horizontally
--
move :: ColourPoint -> Int -> Int -> ColourPoint
move (x, y, colour) xDistance yDistance
        = (x + xDistance, y + yDistance, colour)

-- compute the distance between two colour points
--
distance :: ColourPoint -> ColourPoint -> Float
distance (x1, y1, colour1) (x2, y2, colour2)
  = sqrt (fromIntegral (dx * dx + dy * dy))
  where
    dx = x2 - x1
    dy = y2 - y1

firstTenPrimes :: [Int]
firstTenPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 27]

oneToTwenty :: [Int]
oneToTwenty = [1..20]

-- return all positive odd numbers up to maxNumber
oddNumbers :: Int -> [Int]
oddNumbers maxNumber = [1, 3..maxNumber]

-- 1 : [1,2,3] == [1, 1, 2, 3]
-- [1, 2, 3] ++ [4, 5, 6] == [1, 2, 3, 4, 5, 6]
-- [1, 2, 3, 4] !! 2 == 3
-- head [1, 2, 3] == 1
-- tail [1, 2, 3] == [2, 3]
-- head :: [a] -> a
-- head (x:xs) = x
-- head "string" == 's'
-- tail "string" == "tring"
-- length [0, 1, 2, 3] == 4
-- elem :: Eq a => a -> [a] -> Bool
-- elem 2 [0, 1, 2, 3] == True
-- elem 5 [0, 1, 2, 3] == False
-- maximum :: Ord a => [a] -> a
-- minimum :: Ord a => [a] -> a
-- sum     :: Num a => [a] -> a
-- product :: Num a => [a] -> a

-- head is a partial function, which means that applying head to an empty list will result in an error
-- on the other hand, length will always return a meaningful value, hence a total function

sort2 :: Ord a => a -> a -> (a, a)
-- sort2 x y = if x >= y then (x, y) else (y, x)
sort2 x y | x >= y = (x, y)
          | otherwise = (y, x)

-- almostEqual :: Eq a => (a, a) -> (a, a) -> Bool 
-- almostEqual (x1, y1) (x2, y2)                -- this one seems adequate
--   | (x1 == x2) && (y1 == y2) = True
--   | (x1 == y2) && (y1 == x2) = True
--   | otherwise                = False

-- almostEqual (x1, y1) (x2, y2)                -- does pattern matching work this way too? looks like it will throw an error
--   | (x1 == x2) = (y1 == y2) 
--   | (x1 == y2) = (y1 == x2) 
--   | otherwise  = False

-- almostEqual pair1 pair2                      -- simple, but ducktyping, which might lead to human error
--   = (pair1 == pair2) || (swap pair1 == pair2)
--   where 
--     swap (x,y) = (y,x)

-- almostEqual pair1 pair2                      -- wrong
--   = (pair1 == pair2) || (swap pair1 == swap pair2)
--   where 
--     swap (x,y) = (y,x)

-- almostEqual (x1, y1) (x2, y2)                -- too verbose
--   = if (x1 == x2) 
--       then
--         if (y1 == y2) 
--           then True
--           else False
--       else 
--         if (x1 == y2) 
--           then 
--             if (x2 == y1)
--               then True
--               else False
--           else False

isLower :: Char -> Bool
isLower = isAsciiLower
-- isLower c = elem c ['a'..'z']

mangle :: String -> String
mangle s | not(null s) = tail s ++ [head s]
         | otherwise = ""

divide :: Int -> Int -> Int
divide x y = Prelude.length [x, x*2..y]

natsum :: Int -> Int
natsum x | x > 0 = x + natsum(x-1)
         | otherwise = 0

product :: Num a => [a] -> a
product = foldr (*) 1

repeatN :: Int -> a -> [a]
repeatN 0 val = []
repeatN n val = val : repeatN (n-1) val

suffixes :: String -> [String]
suffixes "" = []
suffixes s = s : suffixes (tail s)

allSquares :: Num a => [a] -> [a]
allSquares = map (\ x -> x * x)
-- allSquares []           = []
-- allSquares (x : xs)     = x * x : allSquares xs

allToUpper :: String -> String
allToUpper = map toUpper

distanceFromPoint :: ColourPoint -> [ColourPoint] -> [Float]
-- distanceFromPoint point []
--         = []
-- distanceFromPoint point (p : ps)
--         = distance point p : distanceFromPoint point ps
-- distanceFromPoint point ps
--         = map (distance point) ps
distanceFromPoint point
        = map (distance point)

extractDigits :: String -> String
extractDigits []
        = []
extractDigits (chr : restString)
        | isDigit chr = chr : extractDigits restString
        | otherwise   =       extractDigits restString

inRadius :: ColourPoint -> Float -> [ColourPoint] -> [ColourPoint]
inRadius point radius []
        = []
inRadius point radius (p : ps)
        | distance point p <= radius = p : inRadius point radius ps
        | otherwise                  =     inRadius point radius ps

minList :: [Int] -> Int
minList [x] = x
minList (x:xs) = min x (minList xs)
-- minList []           = maxBound
-- minList (x:xs)       = x `min` minList xs

reverse :: [a] -> [a]
reverse [] = []
reverse (x : xs) = Tutorial.reverse xs ++ [x]

deductFromAccount :: Int -> [Int] -> Int
deductFromAccount balance []
        = balance
deductFromAccount balance (d : ds)
        | balance < d = error ("Your account balance is " ++ show balance ++
                               " - cannot deduct " ++ show d ++ " cents")
        | otherwise   = deductFromAccount (balance - d) ds

stringToInt :: String -> Int
stringToInt = stringToIntAcc 0
        where
                stringToIntAcc :: Int -> String -> Int
                stringToIntAcc acc []
                        = acc
                stringToIntAcc acc (chr : restString)
                        = stringToIntAcc (10 * acc + digitToInt chr) restString

fastReverse :: [a] -> [a]
fastReverse xs = reverseAcc [] xs
        where
                reverseAcc :: [a] -> [a] -> [a]
                reverseAcc accList []           = accList
                reverseAcc accList (x : xs)     = reverseAcc (x : accList) xs

betterSum :: Num a => [a] -> a
betterSum xs = sumAcc 0 xs
        where
                sumAcc :: Num a => a -> [a] -> a
                sumAcc acc []           = acc
                sumAcc acc (x : xs)     = sumAcc (acc + x) xs -- Due to tail call recursion's performance, this function is more optimised than the sum function declared above


sumEvenElems :: (Num a, Integral a) => [a] -> a
sumEvenElems []
        = 0
sumEvenElems (x : xs)
        | even x        = x + sumEvenElems xs
        | otherwise     = sumEvenElems xs

-- sumOfSquareRoots :: (Floating a, Ord a) => [a] -> a
-- sumOfSquareRoots xs = sum (allSquareRoots (filterPositives xs))
--         where
--                 allSquareRoots []       = []
--                 allSquareRoots (x:xs)   = sqrt x : allSquareRoots xs

--                 filterPositives []      = []
--                 filterPositives (x:xs)
--                         | x > 0         = x : filterPositives xs
--                         | otherwise     = filterPositives xs

sumOfSquareRoots :: (Ord p, Floating p) => [p] -> p
sumOfSquareRoots [] = 0
sumOfSquareRoots (x:xs)
        | x > 0         = sqrt x + sumOfSquareRoots xs
        | otherwise     = sumOfSquareRoots xs


-- type Point = (Float, Float)

closestPoint :: Point -> [Point] -> Point
closestPoint p pts = closestPointAcc p pts Prelude.Nothing
        where
                closestPointAcc :: Point -> [Point] -> Maybe Point -> Point
                closestPointAcc p (x : xs) Prelude.Nothing = closestPointAcc p xs (Prelude.Just x)
                closestPointAcc p [] Prelude.Nothing = error "No closest point."
                closestPointAcc p [] (Prelude.Just a) = a
                closestPointAcc p (x : xs) (Prelude.Just a)
                        | pointDistance p x < pointDistance p a = closestPointAcc p xs (Prelude.Just x)
                        | otherwise                             = closestPointAcc p xs (Prelude.Just a)

                pointDistance :: Point -> Point -> Float
                pointDistance (Point x0 y0) (Point x1 y1) = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0))

-- Define the function length :: [a] -> Int. It is quite similar to sum and product in the way it traverses its input list. 
length :: [a] -> Int
length x = lengthAcc x 0
        where
                lengthAcc :: [a] -> Int -> Int
                lengthAcc [] acc        = acc
                lengthAcc (_:xs) acc    = lengthAcc xs acc+1

-- Write a recursive function fact to compute the factorial of a given positive number (ignore the case of 0 for this exercise).
fact :: Int -> Int
fact n = factAcc n 1
        where
                factAcc :: Int -> Int -> Int
                factAcc 0 acc = acc
                factAcc n acc
                        | n < 0         = error "No negative values allowed!"
                        | otherwise     = factAcc (n-1) (acc*n)

-- Write a recursive function enumFromTo which produces such a list given m and n, such that
enumFromTo :: Int -> Int -> [Int]
enumFromTo a b = if b >= a then enumFromToAcc a b [] else error "Not applicable"
        where
                enumFromToAcc :: Int -> Int -> [Int] -> [Int]
                enumFromToAcc start cur en
                        | start == cur  = cur:en
                        | otherwise     = enumFromToAcc start (cur-1) (cur:en)

-- Write a recursive function countOdds which calculates the number of odd elements in a list of Int values:
countOdds :: [Int] -> Int
countOdds x = countOddsAcc x 0
        where
                countOddsAcc :: [Int] -> Int -> Int
                countOddsAcc [] acc     = acc
                countOddsAcc (x:xs) acc
                        | odd x         = countOddsAcc xs acc+1
                        | otherwise     = countOddsAcc xs acc

-- Write a recursive function removeOdd that, given a list of integers, removes all odd numbers from the list, e.g.,
removeOdd :: [Int] -> [Int]
removeOdd x = removeOddAcc x []
        where
                removeOddAcc [] acc     = acc
                removeOddAcc (x : xs) acc
                        | odd x         = removeOddAcc xs acc
                        | otherwise     = removeOddAcc xs (acc++[x]) -- stable order

-- Challenge: At the end of the last screencast, demonstrating the implementation of closestPoint :: Point -> [Point] -> Point, 
-- we mentioned that the final implementation is less efficient than one might hope, 
-- as it uses the distance functions twice —instead of once— per recursive step. Improve the implementation to avoid that inefficiency.
-- ^ above, 284~296

type Line = (Point, Point)
type Path = [Point]
-- type Colour = (Int, Int, Int, Int) -- values are between 0 and 255
type Picture = [(Colour, Path)]

-- white, black, blue, red, green, lightgreen, oragne, magenta :: Colour

spiralRays :: Float -> Float -> Int -> Colour -> Line -> Picture
spiralRays angle scaleFactor n colour line -- line == line, fst line == p1, snd line == p2
        = spiralRays' n colour line
        where
                spiralRays' n colour line@(p1, p2)
                        | n <= 0        = []
                        | otherwise     = (colour, [p1, p2]) : spiralRays' (n-1) newColour newLine
                        where
                                newColour       = fade colour
                                newLine         = scaleLine scaleFactor (roateLine angle line)

roateLine :: Float -> Line -> Line
roateLine alpha (Point x1 y1, Point x2 y2)
        = (Point x1 y1, Point (x' + x1) (y' + y1))
        where
                x0 = x2 - x1
                y0 = y2 - y1
                x' = x0 * cos alpha - y0 * sin alpha
                y' = x0 * sin alpha + y0 * cos alpha

scaleLine :: Float -> Line -> Line
scaleLine factor (Point x1 y1, Point x2 y2)
        = (Point x1 y1, Point (x' + x1) (y' + y1))
        where
                x0 = x2 - x1
                y0 = y2 - y1
                x' = factor * x0
                y' = factor * y0

fade :: Colour -> Colour
fade (Colour redC greenC blueC opacityC)
        = Colour redC greenC blueC (opacityC - 1)

map :: (a -> b) -> [a] -> [b]
map f xs = map f xs

average :: Float -> Float -> Float
average a b = (a + b) / 2.0

-- zipWith average [1, 2, 3] [4, 5, 6]

filter :: (a -> Bool) -> [a] -> [a]
filter p []
        = []
filter p (x : xs)
        | p x           = x : filter p xs
        | otherwise     = filter p xs

-- functionName a1 a2 ... an = body == \a1 a2 ... an -> body -- lambda (anonymous function) in Haskell

foldr :: (a -> b -> b) -> b -> [a] -> b
foldr = foldr

foldl :: (b -> a -> b) -> b -> [a] -> b
foldl op acc []         = acc
foldl op acc (x : xs)   = foldl op (acc `op` x) xs

-- sumOfSquareRoots = sum $ map sqrt $ filter (>0) -- compile error
-- sumOfSquareRoots = sum . map sqrt . filter (>0) -- compile

-- 1. Define our old friend natSum :: Num a => a -> a (which sums the numbers from 1 up to the given argument) in terms of
-- enumFromTo n m
--   | n > m     = []
--   | otherwise = n : enumFromTo (n + 1) m
-- and one of the list combinators introduced in this chapter.

natSum :: (Num a, Enum a) => a -> a
natSum = sum . Prelude.enumFromTo 1

-- The map function is just a special case of foldr. Can you rewrite the map definition in terms of foldr? Complete the following definition:

myMap :: (a -> b) -> [a] -> [b]
myMap f = map f

spiralRays' :: Int -> (Int -> Colour) -> Line -> Picture
spiralRays' n f line@(p1, p2)
        | n <= 0        = []
        | otherwise     = (f n, [p1, p2]) : spiralRays' (n-1) f newLine
        where
                newLine :: Line
                newLine         = scaleLine 1.02 (roateLine (pi / 40) line)

type FancyLine = (Point, Point, LineStyle)
-- type LineStyle = String

-- changeLineStyle :: FancyLine -> LineStyle -> FancyLine
-- changeLineStyle (x, y, _) newStyle
--   | newStyle `elem` ["solid", "dashed", "dotted"] = (x, y, newStyle)
--   | otherwise 
--   = error $ "error in changeLineStyle: " ++ newStyle ++ " is not a valid style" -- bad style -- errors can only be spotted at runtime

data LineStyle -- equivalent to enum
        = Solid
        | Dashed
        | Dotted
        deriving (Show, Eq)

myLine :: FancyLine
myLine = (Point 0 0, Point 1 1, Dashed) -- now error can be checked at compile-time

data Day
        = Sunday
        | Monday
        | Tuesday
        | Wednesday
        | Thursday
        | Friday
        | Saturday
        deriving (Enum, Eq, Show) -- tells Haskell compiler to include the Day datatype into the standard type class Enum

someData :: [Day]
someData = [Sunday .. Saturday] -- without the deriving part in Day declaration, this doesn't work

-- isWeekday :: Day -> Bool
-- isWeekday Sunday = False 
-- isWeekday Saturday = False 
-- isWeekday _ = True 

-- isWeekday :: Day -> Bool
-- isWeekday d = case d of
--         Sunday -> False
--         Saturday -> False
--         _ -> True

isWeekday :: Day -> Bool
isWeekday d = notElem d [Sunday, Saturday] -- deriving Eq makes it possible to use elem here. Rule of thumbs, usually it is a good idea to include certain type classes in the deriving section, eg) Show

-- type synonyms (Point = (Float, Float)) helps developers to distinguish variables, but doesn't help compilers distinguish them, as long as two variables have the same signature, compilers won't complain

data Point = Point { xPoint     :: Float
                    ,yPoint     :: Float
        }
        deriving (Show, Eq) -- by declaring this data type, the constructor 
        -- Point :: Float -> Float -> Point
        -- Point x y is also implemented automatically 

data Vector = Vector Float Float
        deriving (Show, Eq)

pointToVector :: Point -> Vector
pointToVector (Point x y) = Vector x y

movePointN :: Float -> Vector -> Point -> Point
movePointN n (Vector vx vy) (Point x y)
        = Point (n * vx + x) (n * vy + y)

data Colour
        = Colour { redC         :: Int
                  ,greenC       :: Int
                  ,blueC        :: Int
                  ,opacityC     :: Int
        }
        deriving (Show, Eq)

red :: Colour
red = Colour 255 0 0 255

blue :: Colour
blue = Colour {redC = 0, greenC = 0, blueC = 255, opacityC = 255}

getGreenComponent :: Colour -> Int
getGreenComponent = greenC -- Colour data type automatically generates this pattern matching variable
-- getGreenComponent Colour {redC= _, greenC = green, blueC = _, opacityC = _}
--         = green

getRedComponent :: Colour -> Int
getRedComponent Colour {redC = red} = red

data FillStyle
        = NoFill
        | SolidFill
        deriving (Show, Eq)

-- data PictureObject 
--   = Path    [Point]                   Colour LineStyle 
--   | Circle  Point   Float             Colour LineStyle FillStyle 
--   | Ellipse Point   Float Float Float Colour LineStyle FillStyle 
--   | Polygon [Point]                   Colour LineStyle FillStyle
--   deriving (Show, Eq) -- now Path, Circle, Ellipse, Polygon are all a kind of PictureObject (called SumType in Haskell)

-- record update 
-- <Expr> { <FieldName1> = <Expr1>, … <FieldNameN> = <ExprN> }

aPoint :: Point
aPoint = (Point 10 20){ xPoint= 30 } -- aPoint == Point 30 20

data PictureObject
  = Path
    { pointsPO    :: [Point]
    , colourPO    :: Colour
    , lineStylePO :: LineStyle
    }
  | Circle
    { centerPO    :: Point
    , radiusPO    :: Float
    , colourPO    :: Colour -- different constructors in the same sumType may have same field names
    , lineStylePO :: LineStyle
    , fillStylePO :: FillStyle
    }
  | Ellipse
    { centerPO    :: Point
    , widthPO     :: Float
    , heightPO    :: Float
    , rotationPO  :: Float
    , colourPO    :: Colour
    , lineStylePO :: LineStyle
    , fillStylePO :: FillStyle
    }
  | Polygon
    { pointsPO    :: [Point]
    , colourPO    :: Colour
    , lineStylePO :: LineStyle
    , fillStylePO :: FillStyle
    }
  deriving (Show, Eq)

setLineStyle :: PictureObject -> LineStyle -> PictureObject
setLineStyle po newLineStyle = po{ lineStylePO = newLineStyle } -- simplified function, no copying, no nothing

rotatePoint :: Float -> Point -> Point -> Point
rotatePoint alpha (Point x0 y0) (Point x y)
        = Point (cos alpha * nx - sin alpha * ny + x0)
                (sin alpha * nx + cos alpha * ny + y0)
        where
                nx = x - x0
                ny = y - y0

rotatePictureObject :: Float -> Point -> PictureObject -> PictureObject
rotatePictureObject angle point picObj@Circle{}
  = picObj{ centerPO = rotatePoint angle point $ centerPO picObj }
rotatePictureObject angle point picObj@Ellipse{}
  = picObj{ centerPO   = rotatePoint angle point $ centerPO picObj
          , rotationPO = rotationPO picObj + angle
          }
rotatePictureObject angle point picObj
  = picObj{ pointsPO = map (rotatePoint angle point) $ pointsPO picObj }

-- 1. Rewrite the defintion of map

-- map :: (a -> b) -> [a] -> [b]
-- map f [] = []
-- map f (x : xs) = f x : map f xs
-- to use case notation — i.e., complete the following definition

anotherMap :: (a -> a) -> [a] -> [a]
anotherMap f xs = case xs of
        (xh : xt) -> f xh : anotherMap f xt
        []        -> []

nextDay :: Day -> Day
nextDay d = toEnum (mod (fromEnum d + 1) 7)

data TrumpValue =
        TrumpAce
        | TrumpTwo
        | TrumpThree
        | TrumpFour
        | TrumpFive
        | TrumpSix
        | TrumpSeven
        | TrumpEight
        | TrumpNine
        | TrumpTen
        | TrumpJ
        | TrumpQ
        | TrumpK
        deriving (Show, Eq, Enum)

data Trump =
        Spade { cardNum :: TrumpValue
        }
        | Diamond { cardNum :: TrumpValue
        }
        | Heart { cardNum :: TrumpValue
        }
        | Clover { cardNum :: TrumpValue
        }
        deriving (Show, Eq)

trumpToNum :: Trump -> Int
trumpToNum trump = case trumpValue of
        TrumpAce-> 11
        TrumpJ  -> 10
        TrumpQ  -> 10
        TrumpK  -> 10
        _       -> fromEnum trumpValue + 1
        where
                trumpValue :: TrumpValue
                trumpValue = cardNum trump

blackJack :: [Trump] -> Int
blackJack cards = (\n -> if n <= 21 then n else n - 21) $ sum $ Tutorial.map trumpToNum cards

data MaybeInt a
        = Just a
        | Nothing

(!+!) :: Show a => [a] -> Int -> MaybeInt a
[]      !+! _ = Tutorial.Nothing
(x : _) !+! 0 = Tutorial.Just x
(_ : xs)!+! n = xs !+! (n-1)

showFifthElement :: Show a => [a] -> String
showFifthElement xs
        = case xs !+! 4 of
                Tutorial.Nothing -> "there is no fifth element in this list"
                Tutorial.Just n -> "the fifth element of the list is " ++ show n

-- data Maybe a
--         = Just a
--         | Nothing

-- isElement :: Eq a => a -> [a] -> Bool -- Too time-consuming O(n)
-- isElement _ []          = False 
-- isElement a (x:xs)
--         | a == x        = True 
--         | otherwise     = isElement a xs

-- precondition: list is sorted in increasing order
-- isElementSorted :: Ord a => a -> [a] -> Bool -- but this improvement is not free, as we have to sort the list
-- isElementSorted _ []    = False 
-- isElementSorted a (x:xs)
--         | a == x        = True 
--         | a > x         = False
--         | otherwise     = isElementSorted a xs

-- precondition: list is sorted in increasing order
-- postconditioni: return list is sorted in increasing order
-- insertSorted :: Ord a => a -> [a] -> Bool
-- insertSorted x []       = [x]
-- insertSorted x (y:ys)
--         | x <= y        = x : y : ys
--         | otherwise     = y : insertSorted x ys

-- implement Tree
data BinaryTree a
        = Node a (BinaryTree a) (BinaryTree a)
        | Leaf

-- precondition: tree is sorted in increasing order
-- postcondition: return tree is sorted in increasing order
insertTree :: Ord a => a -> BinaryTree a -> BinaryTree a
insertTree x Leaf
        = Node x Leaf Leaf
insertTree newValue (Node nodeValue leftSubTree rightSubTree)
        | newValue < nodeValue  = Node nodeValue (insertTree newValue leftSubTree) rightSubTree
        | otherwise             = Node nodeValue leftSubTree (insertTree newValue rightSubTree)

isElementTree :: Ord a => a -> BinaryTree a -> Bool
isElementTree x Leaf = False
isElementTree value (Node nodeValue leftSubTree rightSubTree)
        | value == nodeValue    = True
        | value < nodeValue     = isElementTree value leftSubTree
        | otherwise             = isElementTree value rightSubTree

-- balancing is a big issue in Tree, if 


-- new type
-- data Celsius    = Celsius       Float   -- those two types cannot be used interchangeably
-- data Fahrenheit = Fahrenheit    Float

-- above can be rewritten as below
newtype Celsius         = Celsius Float
newtype Fahrenheit      = Fahrenheit Float

myHead :: [a] -> Maybe a
myHead l@(x:_)
        | not $ null l = Prelude.Just x
        | otherwise = Prelude.Nothing

myTail :: [a] -> Maybe [a]
myTail l@(_:xs)
        | not $ null xs = Prelude.Just xs
        | otherwise = Prelude.Nothing

myLength :: [a] -> Int
myLength l = myLengthAcc l 0
        where
                myLengthAcc :: [a] -> Int -> Int
                myLengthAcc [] i = 0
                myLengthAcc l@(_:xs) i = case myTail l of
                        Prelude.Nothing -> i+1
                        _ -> myLengthAcc xs i+1

deleteSorted :: Ord a => a -> [a] -> [a]
deleteSorted target list@(x:xs)
        | target == x   = xs
        | target > x    = list
        | otherwise     = x : deleteSorted target xs

deleteSmallestTree :: Ord a => BinaryTree a -> BinaryTree a
deleteSmallestTree Leaf = Leaf
deleteSmallestTree (Node nodeValue leftSubTree rightSubTree) = case leftSubTree of
        Node {} -> Node nodeValue (deleteSmallestTree leftSubTree) rightSubTree
        Leaf    -> rightSubTree

treeToList :: Ord a => BinaryTree a -> [a] -- pre-order, in-order, post-order
treeToList Leaf = []
treeToList (Node nodeValue leftSubTree rightSubTree) = treeToList leftSubTree ++ [nodeValue] ++ treeToList rightSubTree

buildTree :: Ord a => a -> BinaryTree a -> BinaryTree a
buildTree value Leaf = Node value Leaf Leaf
buildTree value (Node nodeValue leftSubTree rightSubTree)
        | value < nodeValue     = Node nodeValue (buildTree value leftSubTree) rightSubTree
        | otherwise             = Node nodeValue leftSubTree (buildTree value rightSubTree) -- same values go to the right side

midFirst :: Ord a => [a] -> [a]
midFirst l@(x:xs) = l !! halfIdx : theOtherList xs 1
        where
                halfIdx :: Int
                halfIdx = div (Prelude.length l) 2
                theOtherList :: [a] -> Int -> [a]
                theOtherList (x:xs) idx
                        | idx == halfIdx        = xs
                        | otherwise             = x : theOtherList xs (idx+1)

deleteTree :: Ord a => a -> BinaryTree a -> BinaryTree a
deleteTree target Leaf = Leaf
deleteTree target (Node nodeValue leftSubTree rightSubTree)
        | target < nodeValue    = Node nodeValue (deleteTree target leftSubTree) rightSubTree
        | target > nodeValue    = Node nodeValue leftSubTree (deleteTree target rightSubTree)
        | target == nodeValue   = foldr buildTree Leaf listedMidFirst
                where
                        listedMidFirst = innerMidFirst $ treeToList leftSubTree ++ treeToList rightSubTree

                        innerMidFirst :: [a] -> [a]
                        innerMidFirst l@(x:xs) = l !! halfIdx : theOtherList xs 1
                                where
                                        halfIdx :: Int
                                        halfIdx = div (Prelude.length l) 2
                                        theOtherList :: [a] -> Int -> [a]
                                        theOtherList (x:xs) idx
                                                | idx == halfIdx        = xs
                                                | otherwise             = x : theOtherList xs (idx+1)