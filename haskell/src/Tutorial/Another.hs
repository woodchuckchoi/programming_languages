module Tutorial.Another
where

  listComprehension :: Enum a => [a] -> Int
  listComprehension list = sum [1 | _ <- list]

  allPos :: [(String, String)]
  allPos = [(x, y) | x <- ["Some", "Any"], y <- ["Data", "Variable"]] -- [("Some", "Data"), ("Some", "Variable"), ("Any", "Data"), ("Any", "Variable")]

  trianglePos :: Int -> [(Int, Int, Int)]
  trianglePos n = [ (a, b, c) | a <- [1..n], b <- [1..n], c <- [1..n], a^2 + b^2 == c^2]

  removeNonUpperCase :: String -> String
  removeNonUpperCase string = [c | c <- string, c `elem` ['A'..'Z']]

  -- most-used typeclasses
  -- Eq -- == != for equality testing 
  -- Ord -- > < <= >= for ordering
  -- Show -- for printing the varialbe to stdout
  -- Read -- the opposite of Show
  -- Enum -- sequentially ordered types
  -- Bounded -- for setting upper and lower bounds
  -- Num -- for acting like numbers
  -- Integral -- whole numbers such as Int, Integer
  -- Floating -- floating point numbers such as Float, Double

  -- val = read "3" -- doesn't work as the compiler doesn't know what type val is

  val :: Int
  val = read "3" + 5 -- or val = read "3"

  cylinder :: (RealFloat a) => a -> a -> a
  cylinder r h =
    let sideArea = 2 * pi * r * h -- these let values are only available in this guard
        topArea = pi * r ^ 2
    in sideArea + 2 * topArea

  quickSort :: (Ord a) => [a] -> [a]
  quickSort [] = []
  quickSort (x:xs) = smallerSorted ++ [x] ++ biggerSorted
    where
      smallerSorted = quickSort (filter (<=x) xs)
      biggerSorted  = quickSort (filter (>x) xs)

  largestDivisible :: (Integral a) => a
  largestDivisible = head (filter p [100000, 99999..])
    where p x = x `mod` 3829 == 0

  allSquareOddUnder10000 :: Integer
  allSquareOddUnder10000 = sum (takeWhile (<10000) (filter odd (map (^2) [1..])))
  -- allSquareOddUnder10000 = sum (takeWhile (<10000) [n^2 | n <- [1..], odd (n^2)])

  chain :: (Integral a) => a -> [a]
  chain 1 = [1]
  chain n
    | even n    = n:chain (n `div` 2)
    | otherwise = n:chain (n*3 + 1)

  chainsGreaterThan15Under100 :: [Int]
  chainsGreaterThan15Under100 = filter (\n -> length (chain n) > 15) [100,99..1]

  -- maximum' :: (Ord a) => [a] -> a  
  -- maximum' = foldr1 (\x acc -> if x > acc then x else acc)  
    
  -- reverse' :: [a] -> [a]  
  -- reverse' = foldl (\acc x -> x : acc) []  
    
  -- product' :: (Num a) => [a] -> a  
  -- product' = foldr1 (*)  
    
  -- filter' :: (a -> Bool) -> [a] -> [a]  
  -- filter' p = foldr (\x acc -> if p x then x : acc else acc) []  
    
  -- head' :: [a] -> a  
  -- head' = foldr1 (\x _ -> x)  
    
  -- last' :: [a] -> a  
  -- last' = foldl1 (\_ x -> x)  

  sqrtSums :: Int
  sqrtSums = length (takeWhile (<1000) (scanl1 (+) (map sqrt [1..]))) + 1

  fn x = ceiling (negate (tan (cos (max 50 x))))  -- == fn = ceiling . negate . tan . cos . max 50
  -- sum (replicate 5 (max 6.7 8.9)) == (sum . replicate 5 . max 6.7) 8.9 or sum . replicate 5 . max 6.7 $ 8.9
  -- oddSquareSum = sum (takeWhile (<10000) (filter odd (map (^2) [1..]))) == oddSquareSum = sum . takeWhile (<10000) . filter odd . map (^2) $ [1..]  

  -- import Data.List (nub, sort)   selective import
  -- import Data.List hiding (nub)  selective import (negative) 
  -- import qualified Data.Map      functions from Data.Map that have the same function name can only be accessed by Data.Map.func
  -- import Data.Map as MM          rename imported module
