select employee_id
from Employees
where salary < 30000
    and manager_id is not null
    and manager_id not in(
        select employee_id
        from Employees
    )
order by employee_id;

-- select e.employee_id
-- from (
--     select *
--     from Employees
--     where salary < 30000
-- ) e
-- where e.manager_id not in (
--     select employee_id
--     from Employees
-- )
-- order by employee_id;