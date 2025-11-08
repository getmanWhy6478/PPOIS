
| Entity | Fields | Behaviors | Associations |
|--------|--------|-----------|-------------|
| Add | 3 | 6 | |
| Address | 3 | 6 | |
| AirGrill | 1 | 2 | |
| Bike | 1 | 2 | |
| Bonus | 3 | 8 | |
| Car | 1 | 2 | |
| CEO | 0 | 2 | → Restaurant, Manager|
| ComboMeal | 4 | 10 | → Eatable |
| Complaint | 1 | 2 | |
| ComplaintBook | 1 | 3 | → Complaint|
| Cook | 1 | 4 | → Restaurant, Product|
| Courier | 1 | 3 | |
| Customer | 3 | 11 | → Order, OrderPosition, Restaurant, Rating, ComplaintBook, Complaint |
| Delivery | 5 | 11 | → Courier, Order, DeliveryRoute, DeliveryStatus. Vehicle |
| DeliveryRoute | 3 | 7 | |
| DeliveryStatus | 3 | 5 | |
| DinningRoom | 3 | 6 | → DinningRoomRequirements|
| DinningRoomRequirements | 2 | 5 | |
| Dishwasher | 1 | 2 | |
| Drink | 2 | 4 | |
| Eatable | 3 | 6 | |
| Food | 2 | 5 | → FoodPosition|
| FoodPosition| 2 | 4 | → Product |
| Freezer | 1 | 2 | |
| Fridge | 1 | 2 | |
| Kitchen | 4 | 8 | → KitchenAppliance, KitchenRequirement|
| KitchenAppliance | 3 | 6 | |
| KitchenRequirement | 2 | 5 | |
| LoyaltyProgram | 4 | 8 | |
| Manager | 0 | 6 |→ Cook, Courier, Restaurant, Eatable |
| Menu | 1 | 5 | → Eatable |
| NotAuthorisedCustomer | 2 | 6 |→ Order, OrderPosition, Restaurant |
| Order | 5 | 13 | → OrderPosition |
| OrderPosition | 3 | 6 | → Eatable |
| Oven | 1 | 2 | |
| Payment | 5 | 10 | |
| Place | 1 | 2 | |
| PlaceRequirement | 3 | 7 | |
| Product | 2 | 3 | |
| PushNotification | 3 | 6 | |
| PushService | 1 | 2 | |
| Rating | 2 | 4 | |
| Restaurant | 10 | 22 | → Adress, DinningRoom, Cook, Courier, Manager, Warehouse, Order, Rating, Menu |
| Scooter | 1 | 2 | |
| Stove | 1 | 2 | |
| Supplier | 0 | 1 | → FoodPosition, Warehouse |
| SupportAgent | 0 | 2 | → Rating, Restaurant |
| User | 4 | 8 | |
| Vehicle | 2 | 5 | |
| VipCustomer | 2 | 5 | → Order |
| Warehouse | 3 | 7 | → WarehouseRequirements, FoodPosition|
| WarehouseRequirements | 2 | 5 | |
| Worker | 2 | 4 | → Supplier |

## Итоговая статистика

- **Поля:** 124
- **Поведения:** 278
- **Ассоциации:** 49
- **Всего классов:** 52 классов
