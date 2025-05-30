-- Jogo da Forca em Haskell
-- Este arquivo implementa um jogo da forca completo, usando conceitos de programação funcional.

import System.IO (hFlush, stdout)
import Data.Char (toUpper)
import Data.List (nub, intersperse)
import Data.Time.Clock (getCurrentTime, utctDayTime)
import Data.Time.Clock.POSIX (utcTimeToPOSIXSeconds)

-- *** Tipos Algébricos ***
-- Tipo algébrico (soma) para representar o estado do jogo
data GameState = Playing | Won | Lost deriving (Show, Eq)

-- Tipo algébrico (produto) para o jogo, encapsulando os dados principais
data Game = Game
  { secretWord :: String        -- Palavra secreta a ser adivinhada
  , guessedLetters :: [Char]    -- Letras já adivinhadas
  , remainingAttempts :: Int    -- Tentativas restantes
  , gameState :: GameState      -- Estado atual do jogo
  } deriving (Show)

-- *** Classe de Tipo ***
-- Classe de tipo para abstrair a exibição de elementos do jogo
class Displayable a where
  display :: a -> String

-- Número máximo de erros permitidos
maxErrors :: Int
maxErrors = 6

-- Exibe a forca visualmente de acordo com os erros cometidos
displayHangman :: Int -> String
displayHangman n = hangmans !! (min n maxErrors)
  where
    hangmans =
      [ unlines
          [ "  ____"
          , "  |  |"
          , "  |"
          , "  |"
          , "  |"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  |"
          , "  |"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  |  |"
          , "  |"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  | /|"
          , "  |"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  | /|\\"
          , "  |"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  | /|\\"
          , "  | /"
          , "__|__"
          ]
      , unlines
          [ "  ____"
          , "  |  |"
          , "  |  O"
          , "  | /|\\"
          , "  | / \\"
          , "__|__"
          ]
      ]

-- Letras erradas já tentadas
wrongLetters :: Game -> [Char]
wrongLetters game = filter (`notElem` secretWord game) (guessedLetters game)

-- Instância de Displayable para o tipo Game (atualizada)
instance Displayable Game where
  display game = unlines
    [ displayHangman (maxErrors - remainingAttempts game)
    , "Palavra: " ++ intersperse ' ' (displayWord game)
    , "Tentativas restantes: " ++ show (remainingAttempts game)
    , "Letras erradas: " ++ show (wrongLetters game)
    , "Letras adivinhadas: " ++ show (guessedLetters game)
    , "Estado: " ++ show (gameState game)
    ]

-- *** Lógica do Jogo ***
-- Exibe a palavra com '_' para letras não adivinhadas, mas mostra espaços normalmente
displayWord :: Game -> String
displayWord game = [if c == ' ' then ' ' else if c `elem` guessedLetters game then c else '_' | c <- secretWord game]

-- Adiciona uma letra ao jogo e atualiza o estado
guessLetter :: Char -> Game -> Game
guessLetter letter game
  | letter `elem` guessedLetters game = game -- Letra já adivinhada, não altera
  | otherwise = let newGuessed = letter : guessedLetters game
                    newAttempts = if letter `elem` secretWord game
                                  then remainingAttempts game
                                  else remainingAttempts game - 1
                    newState = updateGameState game letter
                in Game (secretWord game) newGuessed newAttempts newState

-- Atualiza o estado do jogo com base na letra adivinhada
updateGameState :: Game -> Char -> GameState
updateGameState game letter
  | all (\c -> c == ' ' || c `elem` (letter : guessedLetters game)) (secretWord game) = Won
  | remainingAttempts game <= 1 && not (letter `elem` secretWord game) = Lost
  | otherwise = Playing

-- Verifica se a letra é válida (apenas letras maiúsculas, ignora espaço)
isValidLetter :: Char -> Bool
isValidLetter c = c `elem` ['A'..'Z']

-- *** Interação com o Usuário (IO) ***
-- Banco de palavras possíveis
wordBank :: [String]
wordBank = ["HASKELL", "PROGRAMACAO", "FUNCIONAL", "MONADA", "TIPO", "LAZINESS", "CURRY", "PATTERN", "RECURSAO", "GUARDS", "LISTA",
             "FUNCAO", "ALGORITMO", "DADOS", "TIPOS", "FUNCOES", "LAMBDA", "RECURSIVIDADE", "JULIO", "MARCAO", "HERMERSON", "RAILDOM", "JOAO MARCOS",
             "COMPUTADOR", "COMPILADOR", "INTERPRETE", "LINGUAGEM", "MEMORIA", "PROCESSADOR", "SEMANTICA", 
             "VARIAVEL", "CONSTANTE", "BIBLIOTECA", "BINARIO", "FRAMEWORK", "ITERACAO", "PARADIGMA", 
             "INTERFACE", "TERMINAL", "LOGICA", "METODO", "OBJETO", "INSTANCIA", "ESCOPO", "MODULO", 
             "PARAMETRO", "RETORNO", "CLASSE", "HERANCA", "ATRIBUTO", "SOFTWARE", "HARDWARE", "INTERNET"
            ]

-- Função para obter um índice pseudoaleatório baseado em frações de segundo
randomIndex :: Int -> IO Int
randomIndex len = do
  t <- getCurrentTime
  let posix = utcTimeToPOSIXSeconds t
      frac = floor (posix * 1000) :: Int
  return (frac `mod` len)

-- Sorteia uma palavra do banco de forma pseudoaleatória
selectWord :: IO String
selectWord = do
  let len = length wordBank
  idx <- randomIndex len
  return (wordBank !! idx)

-- Inicializa o jogo
initialGame :: IO Game
initialGame = do
  w <- selectWord
  return $ Game w [] maxErrors Playing

-- Loop principal do jogo
main :: IO ()
main = do
  putStrLn "Bem-vindo ao Jogo da Forca!"
  jogo

jogo :: IO ()
jogo = do
  limparTela
  game <- initialGame
  gameLoop game

gameLoop :: Game -> IO ()
gameLoop game = do
  limparTela
  putStrLn $ display game
  case gameState game of
    Won -> do
      putStrLn "Parabéns, você venceu!"
      playAgain
    Lost -> do
      putStrLn $ "Fim de jogo! A palavra era: " ++ secretWord game
      playAgain
    Playing -> do
      putStrLn "Digite uma letra (A-Z) ou tente adivinhar a palavra inteira:"
      hFlush stdout
      input <- getLine
      let inputUpper = map toUpper input
      case inputUpper of
        [c] | isValidLetter c -> gameLoop $ guessLetter c game
        [] -> invalid
        _  | removeSpaces inputUpper == removeSpaces (secretWord game) ->
              gameLoop $ game { guessedLetters = nub (guessedLetters game ++ filter (/= ' ') (secretWord game)), gameState = Won }
           | length inputUpper > 1 -> do
                putStrLn "Palavra incorreta!"
                let newGame = game { remainingAttempts = remainingAttempts game - 1
                                   , gameState = if remainingAttempts game - 1 <= 0 then Lost else Playing }
                gameLoop newGame
           | otherwise -> invalid
  where
    invalid = do
      putStrLn "Por favor, digite uma letra válida (A-Z) ou uma palavra."
      gameLoop game

-- Remove espaços de uma string (para comparar palavras compostas)
removeSpaces :: String -> String
removeSpaces = filter (/= ' ')

playAgain :: IO ()
playAgain = do
  putStrLn "Deseja jogar novamente? (S/N)"
  hFlush stdout
  resp <- getLine
  case map toUpper resp of
    ('S':_) -> jogo
    _       -> putStrLn "Obrigado por jogar!"

limparTela :: IO ()
limparTela = do
  putStr "\ESC[2J"  -- Limpa a tela
  putStr "\ESC[H"   -- Move o cursor para o início
  hFlush stdout

-- *** Notas sobre Programação Funcional ***
-- - Listas: Usadas para armazenar letras adivinhadas e manipular a palavra secreta (ex.: displayWord usa compreensão de listas).
-- - Tipos Algébricos: GameState (soma) e Game (produto) modelam o domínio do problema.
-- - Classe de Tipo: Displayable abstrai a exibição do estado do jogo.
-- - ADT: O tipo Game é encapsulado, com funções públicas como guessLetter e displayWord.
-- - IO: A monada IO é usada para interação com o usuário, mantendo a lógica pura separada.