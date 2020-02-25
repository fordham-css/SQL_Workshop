SELECT
    "Order"."OrderDate",
    "OrderDetail"."Quantity",
    "OrderDetail"."UnitPrice",
    "Customer"."CompanyName",
    "Customer"."ContactName",
    "Customer"."City"
FROM "Order"
    LEFT JOIN "OrderDetail" ON "OrderDetail"."OrderId" = "Order"."Id"
    LEFT JOIN "Customer" ON "Customer"."Id" = "Order"."CustomerId";

