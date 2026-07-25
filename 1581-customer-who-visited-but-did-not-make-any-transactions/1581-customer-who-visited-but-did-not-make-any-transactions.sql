select 
    customer_id , count(*) as count_no_trans
from
    Visits
left join 
    Transactions
On 
    Visits.visit_id = Transactions.visit_id
where
    transaction_id Is NULL
group by 
    customer_id;