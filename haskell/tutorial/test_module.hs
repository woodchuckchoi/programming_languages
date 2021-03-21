-- Tutorial Module

module Tutorial
where


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

type Point = (Int, Int)

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
type Colour = String 

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
isLower c = c >= 'a' && c <= 'z'
-- isLower c = elem c ['a'..'z']

mangle :: String -> String 
mangle s | not(null s) = tail s ++ [head s]
         | otherwise = ""

divide :: Int -> Int -> Int
divide x y = length [x, x*2..y]