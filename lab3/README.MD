| Entity | Fields | Behaviors | Associations |
|--------|--------|-----------|-------------|
|Appraisal|7|14|→Artwork|	
|Archive|7|14|→Artwork, Artist|
|Artist|10|21|→Artwork, ArtMovement|
|ArtMovement|6|13|→ Artist|
|Artwork|12|24|→ Artist|
|ArtworkLocation|4|8|→ Room, Storage, Artwork|
|Auction|7|14|	→ Artwork, Collector|
|Catalog|9|18|→ Exhibition, Artwork|
|Ceramics|3|7||
|Collection|6|12|→ Artwork|
|Collector|7|15|→ Collection|
|Conservation|8|16|→ Artwork, Restorer|
|Critic|6|13|→ Rewiew|
|Curator|3|7|→ Exhibition|	
|DigitalArt|6|12||	
|Donation|5|10|→ Artwork|
|Drawing|5|10||
|Employee|8|16|→ Gallery|
|Event|10|21|→ Visitor|
|Exhibition|8|16||
|Gallery|10|20|
|GalleryShop|7|14|→ Gallery|
|Genre|4|8|→ Artwork|
|Guide|4|10|→ Tour|
|Installation|3|6|→ Artwork|
|Insurance|7|15|→ Artwork|
|Lecture|4|8||
|Loan|9|18||
|Membership|9|18|→ Visitor|
|MixedMedia|1|3||
|MultimediaGuide|9|18|→ Artwork|
|Order|7|14|→ Artwork|
|Painting|3|6||
|Period|7|15||
|Photography|3|6||
|PriceCalculator|0|5|→ Membership, Artwork|
|Print|5|10|||
|Provenance|6|12|→ Collector|
|ReportGenerator|0|5|→ Exhibition, Collector|
|Restoration|10|21|→ Artwork, Restorer|
|Restorer|4|9||
|Review|8|17||
|Room|6|12|→ Artwork|
|Sculpture|4|8||
|Security|4|9||
|Storage|5|11|→ Artwork|
|Textile|2|5||
|Ticket|6|12|→ Visitor, Exhibition|
|Tour|8|17|→ Visitor|
|Transportation|6|12||
|Validator|0|6||
|Visitor|10|21||
|Workshop|7|14|

## Итоговая статистика

- **Поля:** 262
- **Поведения:** 523
- **Ассоциации:** 42
- **Всего классов:** 55 классов
