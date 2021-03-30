module Tutorial.Typer
where
  import qualified Data.Map as Map

  data Point = Point Float Float deriving (Show)
  data Shape = Circle Point Float 
              |Rectangle Point Point
              deriving (Show)

  surface :: Shape -> Float 
  surface (Circle _ r) = pi * r ^ 2
  surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1) 

  nudge :: Shape -> Float -> Float -> Shape
  nudge (Circle (Point x y) r) a b = Circle (Point (x+a) (y+b)) r
  nudge (Rectangle (Point x1 y1) (Point x2 y2)) a b = Rectangle (Point (x1+a) (y1+b)) (Point (x2+a) (y2+b))

  baseCircle :: Float -> Shape
  baseCircle r = Circle (Point 0 0) r

  baseRect :: Float -> Float -> Shape
  baseRect width height = Rectangle (Point 0 0) (Point width height)

  data Person = Person {
    firstName :: String,
    lastName :: String,
    age :: Int,
    height :: Float,
    phoneNumber :: String
  } deriving (Read, Show, Eq)

  data Car = Car {
    company :: String,
    model :: String,
    year :: Int
  } deriving (Show)

  data Vector a = Vector a a a deriving (Show)

  vplus :: (Num t) => Vector t -> Vector t -> Vector t
  (Vector x1 y1 z1) `vplus` (Vector x2 y2 z2) = Vector (x1+x2) (y1+y2) (z1+z2)

  vmult :: (Num t) => Vector t -> t -> Vector t
  (Vector x1 y1 z1) `vmult` m = Vector (x1*m) (y1*m) (z1*m)

  scalarMult :: (Num t) => Vector t -> Vector t -> t
  (Vector x1 y1 z1) `scalarMult` (Vector x2 y2 z2) = x1*x2 + y1*y2 + z1*z2

  data Day = Monday
            | Tuesday
            | Wednesday
            | Thursday
            | Friday
            | Saturday
            | Sunday
            deriving (Eq, Ord, Show, Read, Bounded, Enum)

  data LockerState = Taken | Free deriving (Show, Eq)
  
  type Code = String

  type LockerMap = Map.Map Int (LockerState, Code)

  lockerLookup :: Int -> LockerMap -> Either String Code
  lockerLookup lockerNumber map =
    case Map.lookup lockerNumber map of
      Nothing -> Left $ "Locker number " ++ show lockerNumber ++ " doesn't exist!"
      Just (state, code) -> if state /= Taken
                              then Right code
                              else Left $ "Locker " ++ show lockerNumber ++ " is already taken!"

  lockers :: LockerMap
  lockers = Map.fromList
    [(100,(Taken,"ZD39I"))  
    ,(101,(Free,"JAH3I"))  
    ,(103,(Free,"IQSA9"))  
    ,(105,(Free,"QOTSA"))  
    ,(109,(Taken,"893JJ"))  
    ,(110,(Taken,"99292"))  
    ]
  
  data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

  singleton :: a -> Tree a
  singleton x = Node x EmptyTree EmptyTree

  treeInsert :: (Ord a) => a -> Tree a -> Tree a
  treeInsert x EmptyTree = singleton x
  treeInsert x (Node a left right)
    | x == a    = Node x left right
    | x < a     = Node a (treeInsert x left) right
    | otherwise = Node a left (treeInsert x right)

  treeElem :: (Ord a) => a -> Tree a -> Bool 
  treeElem x EmptyTree = False
  treeElem x (Node a left right)
    | x == a    = True
    | x < a     = treeElem a left
    | otherwise = treeElem a right

  data TrafficLight = Red | Yellow | Green
  instance Eq TrafficLight where
    Red == Red = True 
    Green == Green = True 
    Yellow == Yellow = True 
    _ == _ = False

  instance Show TrafficLight where
    show Red = "Red Light"
    show Yellow = "Yellow Light"
    show Green = "Green Light"

  -- instance (Eq m) => Eq (Maybe m) where  
  --   Just x == Just y = x == y  
  --   Nothing == Nothing = True  
  --   _ == _ = False  

  class YesNo a where
    yesno :: a -> Bool

  instance YesNo Int where
    yesno 0 = False 
    yesno _ = True

  instance YesNo [a] where
    yesno [] = False 
    yesno _ = True 

  instance YesNo Bool where
    yesno = id

  instance YesNo (Maybe a) where
    yesno (Just _) = True
    yesno Nothing = False

  instance YesNo (Tree a) where
    yesno EmptyTree = False
    yesno _ = True

  instance YesNo TrafficLight where
    yesno Red = False
    yesno _ = True

  yesnoIf :: (YesNo y) => y -> a -> a -> a
  yesnoIf yesnoVal yesResult noResult = if yesno yesnoVal then yesResult else noResult

  -- class Functor f where
  --   fmap :: (a -> b) -> f a -> f b

  -- instance Functor [] where
  --   fmap = map

  -- fmap (*2) $ Just 3 == Just 6 -- functor acts as a box

  -- instance Functor Maybe where
  --   fmap f (Just x) = Just (f x)
  --   fmap f Nothing = Nothing

  instance Functor Tree where
    fmap f EmptyTree = EmptyTree
    fmap f (Node x left right) = Node (f x) (fmap f left) (fmap f right)

  