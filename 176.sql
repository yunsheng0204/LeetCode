# Write your MySQL query statement below
Select (Select Distinct `salary` from Employee order by `salary` desc LIMIT 1 offset 1) as SecondHighestSalary