
| Entity | Fields | Behaviors | Associations |
|--------|--------|-----------|-------------|
| Add | 3 | 6 | |
| Address | 3 | 6 | |
| AirGrill | 4 | 2 | |
| Bike | 3 | 3 |→ Delivery |
| Bonus | 3 | 7 | |
| Car | 3 | 3 |→ Delivery |
| CEO | 2 | 2 | → Restaurant, Manager|
| ComboMeal | 4 | 10 | → Eatable |
| Complaint | 1 | 2 | |
| ComplaintBook | 1 | 3 | → Complaint|
| Cook | 3 | 4 | → Restaurant, Product|
| Courier | 3 | 3 | |
| Customer | 4 | 8 | → Order, OrderPosition, Restaurant, Rating, ComplaintBook, Complaint, Bonus, LoyaltyProgram |
| Delivery | 6 | 11 | → Courier, Order, DeliveryRoute, DeliveryStatus. Vehicle |
| DeliveryRoute | 3 | 7 | |
| DeliveryStatus | 3 | 5 | |
| DinningRoom | 4 | 6 | → DinningRoomRequirements|
| DinningRoomRequirements | 5 | 5 | |
| Dishwasher | 4 | 2 | |
| Drink | 6 | 6 | |
| Eatable | 4 | 8 | |
| Food | 6 | 7 | → FoodPosition|
| FoodPosition| 2 | 4 | → Product |
| Freezer | 4 | 3 |→ Eatable |
| Fridge | 4 | 3 | → Eatable|
| Kitchen | 3 | 6 | → KitchenAppliance, KitchenRequirement|
| KitchenAppliance | 3 | 6 | |
| KitchenRequirement | 5 | 5 | |
| LoyaltyProgram | 4 | 8 | |
| Manager | 2 | 6 |→ Cook, Courier, Restaurant, Eatable |
| Menu | 1 | 5 | → Eatable |
| NotAuthorisedCustomer | 2 | 6 |→ Order, OrderPosition, Restaurant |
| Order | 5 | 15 | → OrderPosition |
| OrderPosition | 3 | 6 | → Eatable |
| Oven | 4 | 2 | |
| Payment | 5 | 9 | |
| Place | 1 | 2 | |
| PlaceRequirement | 3 | 7 | |
| Product | 2 | 3 | |
| PushNotification | 3 | 6 | |
| PushService | 1 | 2 | |
| Rating | 2 | 4 | |
| Restaurant | 10 | 22 | → Adress, DinningRoom, Cook, Courier, Manager, Warehouse, Order, Rating, Menu |
| Scooter | 3 | 3 |→ DeliveryRoute |
| Stove | 4 | 3 |→ Eatable |
| Supplier | 2 | 1 | → FoodPosition, Warehouse |
| SupportAgent | 0 | 2 | → Rating, Restaurant |
| User | 4 | 8 | |
| Vehicle | 2 | 4 | |
| VipCustomer | 6 | 5 | → Order |
| Warehouse | 3 | 7 | → WarehouseRequirements, FoodPosition|
| WarehouseRequirements | 5 | 5 | |
| Worker | 2 | 4 | → Supplier |

## Итоговая статистика

- **Поля:** 176
- **Поведения:** 289
- **Ассоциации:** 58
- **Всего классов:** 52 классов
