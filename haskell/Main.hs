module Main where

import Another

main :: IO ()
main = print (Another.quickSort [1, 5, 7, 4, 2, 53, 42])
