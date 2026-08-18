# Write your MySQL query statement below
SELECT SalesPerson.name
FROM SalesPerson
WHERE SalesPerson.name NOT IN
(SELECT B.name
FROM 
(
    Orders A
    RIGHT JOIN SalesPerson B
    ON A.sales_id = B.sales_id
    LEFT OUTER JOIN Company C
    ON A.com_id = C.com_id
)
WHERE C.name = 'RED')