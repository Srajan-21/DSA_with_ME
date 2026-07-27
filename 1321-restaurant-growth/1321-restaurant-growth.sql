select
    c.visited_on,
    sum(w.amount) as amount,
    round(sum(w.amount) / 7 , 2) as average_amount

from(
    select 
        visited_on,
        sum(amount) as amount
    from Customer
    group by visited_on
) c

join(
    select
        visited_on,
        sum(amount) as amount
    from Customer
    group by visited_on
) w

on w.visited_on between date_sub(c.visited_on, interval 6 day) and c.visited_on

group by c.visited_on
having count(*) = 7
order by c.visited_on;