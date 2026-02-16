| Entity | Fields | Behaviors | Associations |
|--------|--------|-----------|-------------|
|Appraisal|5|10|→Artwork|	
|Archive|7|14|→Artwork, Artist|
|Artist|10|22|→Artwork, ArtMovement|
|ArtMovement|5|10|→ Artist|
|Artwork|12|24|→ Artist|
|ArtworkLocation|4|8|→ Room, Storage, Artwork|
|Auction|7|14|	→ Artwork, Collector|
|Catalog|9|18|→ Exhibition, Artwork|
|Ceramics|3|7||
|Collection|4|10|→ Artwork|
|Collector|7|15|→ Collection|
|Conservation|7|14|→ Artwork, Restorer|
|Critic|6|13|→ Rewiew|
|Curator|3|7|→ Exhibition|	
|DigitalArt|5|10||	
|Donation|5|10|→ Artwork|
|Drawing|5|10||
|Employee|7|14|→ Gallery|
|Event|10|21|→ Visitor|
|Exhibition|8|16||
|Gallery|10|20|
|GalleryShop|7|14|→ Gallery|
|Genre|4|8|→ Artwork|
|Guide|4|10|→ Tour|
|Installation|3|6|→ Artwork|
|Insurance|7|15|→ Artwork|
|Lecture|3|6||
|Loan|8|16||
|Membership|9|18|→ Visitor|
|MixedMedia|1|3||
|Order|5|10|→ Artwork|
|Painting|3|6||
|Period|6|11||
|Photography|3|6||
|PriceCalculator|0|5|→ Membership, Artwork|
|Print|4|8|||
|Provenance|6|12|→ Collector|
|Recommendation|2|4|→Visitor|
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
|Visitor|11|29|→ Recommendation, Tour, Artwork|
|Workshop|3|6|

## Итоговая статистика

- **Поля:** 190
- **Поведения:** 410
- **Ассоциации:** 44
- **Всего классов:** 55
