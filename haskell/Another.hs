module Another
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
      smallerSorted = quickSort [a | a <- xs, a <= x]
      biggerSorted  = quickSort [a | a <- xs, a > x]