module Main where

  -- import Tutorial.Another as Another

  -- main :: IO ()
  -- -- main = print (Another.quickSort [1, 5, 7, 4, 2, 53, 42])
  -- main = do
  --   putStrLn "Hello World!"
  --   print (Another.quickSort [1, 5, 87, 3, 6, 42, 12, 75, 91])
  --   putStrLn "Name: "
  --   name <- getLine 
  --   putStrLn ("Hey " ++ name) -- main is of type IO () as the last function of the main body.
  -- import Data.Char  
  
  -- main = do  
  --   putStrLn "What's your first name?"  
  --   firstName <- getLine  
  --   putStrLn "What's your last name?"  
  --   lastName <- getLine  
  --   let bigFirstName = map toUpper firstName  
  --       bigLastName = map toUpper lastName  
  --   putStrLn $ "hey " ++ bigFirstName ++ " " ++ bigLastName ++ ", how are you?"  

  -- main = do
  --   line <- getLine 
  --   if null line
  --     then return () -- return is not the equivalent of the same function in imperative programming, in Haskell, all return does is to make IO action out of a pure value
  --     else do
  --       putStrLn $ reverseWords line
  --       main

  -- reverseWords :: String -> String
  -- reverseWords = unwords . map reverse . words

  -- main = do  
  --   return ()                 -- program doesn't end here
  --   return "HAHAHA"           -- neither here
  --   line <- getLine           -- certainly not here
  --   return "BLAH BLAH BLAH"   -- likewise
  --   return 4                  -- obviously
  --   putStrLn line             -- ends here, at the end of the do block, where a function returns something of value IO ()

  -- import Data.Char

  -- main = do
  --   contents <- getContents 
  --   putStr (map toUpper contents)
  -- main = do  
  --   contents <- getContents  
  --   putStr (shortLinesOnly contents)  
  
  -- shortLinesOnly :: String -> String  
  -- shortLinesOnly input =   
  --   let allLines = lines input  
  --       shortLines = filter (\line -> length line < 10) allLines  
  --       result = unlines shortLines  
  --   in  result  

  -- main = interact shortLinesOnly  
  
  -- shortLinesOnly :: String -> String  
  -- shortLinesOnly input =   
  --   let allLines = lines input  
  --       shortLines = filter (\line -> length line < 10) allLines  
  --       result = unlines shortLines  
  --   in  result  

  -- import System.IO

  -- main = do
  --   handle <- openFile "haiku.txt" ReadMode 
  --   contents <- hGetContents handle
  --   putStr contents
  --   hClose handle

  -- main = do
  --   withFile "haiku.txt" ReadMode (\handle -> do
  --     contents <- hGetContents handle
  --     putStr contents)

  -- main = do
  --   toDoItem <- getLine 
  --   appendFile "toDo.txt" (toDoItem ++ "\n")

  -- main = do   
  --   withFile "something.txt" ReadMode (\handle -> do  
  --       hSetBuffering handle $ BlockBuffering (Just 2048)  
  --       contents <- hGetContents handle  
  --       putStr contents)  

  -- import System.IO  
  -- import System.Directory  
  -- import Data.List  
  
  -- main = do        
  --   handle <- openFile "todo.txt" ReadMode  
  --   (tempName, tempHandle) <- openTempFile "." "temp"  
  --   contents <- hGetContents handle  
  --   let todoTasks = lines contents     
  --       numberedTasks = zipWith (\n line -> show n ++ " - " ++ line) [0..] todoTasks     
  --   putStrLn "These are your TO-DO items:"  
  --   putStr $ unlines numberedTasks  
  --   putStrLn "Which one do you want to delete?"     
  --   numberString <- getLine     
  --   let number = read numberString     
  --       newTodoItems = delete (todoTasks !! number) todoTasks     
  --   hPutStr tempHandle $ unlines newTodoItems  
  --   hClose handle  
  --   hClose tempHandle  
  --   removeFile "todo.txt"  
  --   renameFile tempName "todo.txt"  

  -- import System.Environment
  -- import Data.List

  -- main = do
  --   args <- getArgs 
  --   progName <- getProgName 
  --   putStrLn "The arguments are: "
  --   mapM putStrLn args
  --   putStrLn "The program name is: "
  --   putStrLn progName

  -- import System.Environment   
  -- import System.Directory  
  -- import System.IO  
  -- import Data.List  
    
  -- dispatch :: [(String, [String] -> IO ())]  
  -- dispatch =  [ ("add", add)  
  --             , ("view", view)  
  --             , ("remove", remove)  
  --             ]
  
  -- main = do
  --   (command:args) <- getArgs 
  --   let (Just action) = lookup command dispatch
  --   action args

  -- add :: [String] -> IO ()
  -- add [fileName, toDoItem] = appendFile fileName (toDoItem ++ "\n")

  -- view :: [String] -> IO ()
  -- view [fileName] = do
  --   contents <- readFile fileName
  --   let toDoTasks = lines contents
  --       numberedTasks = zipWith (\n line -> show n ++ " - " ++ line) [0..] toDoTasks
  --   putStr $ unlines numberedTasks

  -- remove :: [String] -> IO () 
  -- remove [fileName, numberString] = do
  --   handle <- openFile fileName ReadMode 
  --   (tempName, tempHandle) <- openTempFile "." "temp"
  --   contents <- hGetContents handle
  --   let number = read numberString
  --       toDoTasks = lines contents
  --       newToDoItems = delete (toDoTasks !! number) toDoTasks
  --   hPutStr tempHandle $ unlines newToDoItems
  --   hClose handle
  --   hClose tempHandle
  --   removeFile fileName
  --   renameFile tempName fileName

  -- import System.Random

  -- threeCoins :: StdGen -> (Bool, Bool, Bool)  
  -- threeCoins gen =   
  --   let (firstCoin, newGen) = random gen  
  --       (secondCoin, newGen') = random newGen  
  --       (thirdCoin, newGen'') = random newGen'  
  --   in  (firstCoin, secondCoin, thirdCoin)  
  -- main = do
  --   print (take 5 $ randoms (mkStdGen 11) :: [Int])

  -- finiteRandoms :: (RandomGen g, Random a, Num n) => n -> g -> ([a], g)  
  -- finiteRandoms 0 gen = ([], gen)  
  -- finiteRandoms n gen =   
  --   let (value, newGen) = random gen  
  --       (restOfList, finalGen) = finiteRandoms (n-1) newGen  
  --   in  (value:restOfList, finalGen)  

  -- main = do
  --   gen <- getStdGen 
  --   putStr $ take 20 (randomRs ('a', 'z') gen)

  -- import System.Random  
  -- import Control.Monad(when)  
    
  -- main = do  
  --     gen <- getStdGen  
  --     askForNumber gen  
    
  -- askForNumber :: StdGen -> IO ()  
  -- askForNumber gen = do  
  --   let (randNumber, newGen) = randomR (1,10) gen :: (Int, StdGen)  
  --   putStr "Which number in the range from 1 to 10 am I thinking of? "  
  --   numberString <- getLine  
  --   when (not $ null numberString) $ do  
  --       let number = read numberString  
  --       if randNumber == number   
  --           then putStrLn "You are correct!"  
  --           else putStrLn $ "Sorry, it was " ++ show randNumber  
  --       askForNumber newGen  
  -- import System.Environment  
  -- import System.IO  
  -- import System.Directory  
    
  -- main = do 
  --   (fileName:_) <- getArgs  
  --   fileExists <- doesFileExist fileName  
  --   if fileExists  
  --     then do contents <- readFile fileName  
  --             putStrLn $ "The file has " ++ show (length (lines contents)) ++ " lines!"  
  --     else do putStrLn "The file doesn't exist!"  

import System.Environment  
import System.IO  
import Control.Exception
  
main = toTry `catch` handler  
              
toTry :: IO ()  
toTry = do (fileName:_) <- getArgs  
           contents <- readFile fileName  
           putStrLn $ "The file has " ++ show (length (lines contents)) ++ " lines!"  
  
handler :: IOError -> IO ()  
handler e = putStrLn "Whoops, had some trouble!"  

-- main = do toTry `catch` handler1  
--           thenTryThis `catch` handler2  
--           launchRockets  