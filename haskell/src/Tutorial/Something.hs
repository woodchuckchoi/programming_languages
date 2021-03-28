module Tutorial.Something where
  
  testFunc :: String 
  testFunc = "Test"

  -- currying

  curriedMax5 :: (Num a, Ord a) => a -> a
  curriedMax5 = max 5

  compareWith100 :: (Num a, Ord a) => a -> Ordering
  compareWith100 = compare 100

  divideByTen :: (Floating a) => a -> a
  divideByTen = (/10)

  applyTwice :: (a -> a) -> a -> a -- applyTwice (+3) 10 == 16, applyTwice ("Hello" ++) "Hyuck"
  applyTwice f x = f (f x)

  zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
  zipWith' _ [] _ = []
  zipWith' _ _ [] = []
  zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys --Tutorial.Something.zipWith' (\a b -> show a ++ b) [1,2,3] ["Hey","You","Yes"]
                                                      -- ["1Hey","2You","3Yes"]

  flip' :: (a -> b -> c) -> (b -> a -> c)
  flip' f x y = f y x