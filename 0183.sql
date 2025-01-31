# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE id NOT IN
(
    SELECT A.id
    FROM Customers A
    INNER JOIN Orders B
    ON B.customerId = A.id
)