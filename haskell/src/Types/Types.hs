module Types.Types
where

  data Hyuck a = Oi a
    | Ai
    deriving(Show)

  instance Functor Hyuck where
    fmap f (Oi n) = Oi (f n)
    fmap f Ai = Ai

  -- fmap (+3) (Oi 3) == Oi 6

  -- instance Functor ((->) r) where
  --   fmap f g = (\x -> f (g x))