-- Q1
areaQuadrado :: Float -> Float
areaQuadrado x = x^2

--Q2
soma :: Int -> Int -> Int
soma x y = x + y

--Q3
fatorial :: Int -> Int
fatorial x = if x <= 1 then 1 else x * fatorial(x-1)

--Q4
verifica :: String -> Bool
verifica x = if length x == 10 then True else False

--Q5
first :: String -> Char
first x = head x

--Q6
areaCirculo :: Float -> Float
areaCirculo r = pi * r^2

--Q7 --INCOMPLETA
somaLista :: [Int] -> Int
somaLista list = sum list

--Q8
