select
    p.product_id,
    IFNULL(c.new_price, 10) AS price
from
    (
        select distinct product_id
        from Products
    ) p
left join
    (
        select p1.product_id, p1.new_price
        from Products p1
        join
        (
            select
                product_id,
                max(change_date) as latest_date
            from Products
            where change_date <= '2019-08-16'
            group by product_id
        ) p2
    on p1.product_id = p2.product_id
    and p1.change_date = p2.latest_date
    ) c
on p.product_id = c.product_id;