# Electric Tin Whistle
#### By Jenae Matson

This repository assembles the code, stl files, and documentation to create an electric tin whistle. The electric tin whistle is a simple electric instrument 
that the [tin whistle](https://en.wikipedia.org/wiki/Tin_whistle), a simple woodwind instrument. This can be used as an education project to learn about
programming an Arduino Nano, soldering, digital music synthesis, and how to use components such as a breath sensor and headphone jack. 

This project was created with a mini grant the T3 Makerspace at the University of Alaska Fairbanks.

## Components
This project requires the following parts and components:
- 1 [Arduino Nano](https://www.amazon.com/gp/product/B086GNYXPH/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1)
- 1 [digital pressure sensor](https://www.amazon.com/dp/B0CDWX82PT?ref=ppx_yo2ov_dt_b_fed_asin_title)
- 1 [3.5mm audio jack](https://www.amazon.com/Gikfun-Breakout-Headphone-Arduino-AE1223/dp/B01KFP0HBG/ref=asc_df_B01KFP0HBG/?tag=hyprod-20&linkCode=df0&hvadid=693369603351&hvpos=&hvnetw=g&hvrand=9706526867684402587&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9051751&hvtargid=pla-906246038816&psc=1&mcid=312692fe83e33aeb8c41cdeacfac863e)
- 1 [prototype board](https://www.amazon.com/ElectroCookie-Solderable-Breadboards-Gold-Plated-Multi-Pack/dp/B07ZV9JQY2?psc=1&pd_rd_w=FJyYk&content-id=amzn1.sym.ea1d9533-fbb7-4608-bb6f-bfdceb6f6336&pf_rd_p=ea1d9533-fbb7-4608-bb6f-bfdceb6f6336&pf_rd_r=JANRXB1ZEFYZH6H24N3X&pd_rd_wg=ItuPI&pd_rd_r=e04a170a-0109-4541-bb11-87c19dcb861b&ref_=sspa_dk_detail_1)
- 6 [button switches](https://www.amazon.com/Gikfun-12x12x7-3-Tactile-Momentary-Arduino/dp/B01E38OS7K/ref=sr_1_4?dib=eyJ2IjoiMSJ9.ewlS8tt9zJN3MACZH2CegHgYt7KCbWzXanJ9JsZQqXi8e8q-YkWrlocqXXwiuwSJ0iiAv4NR2kIHHsghUSWK9DENYkUrpILE9H-Tv8Uu3if961sRqMYBeD9Mzx2C2W7_EPsAjLWrm_g3YfDlUAfDWIPkH1r2K7aYYh7D7YWAdhwXW4TUYRSrt_JVyj8sO3dmY_0me3-glqqzeLb_8ZlDJXj4Ym6MKBCdCTW20kCcIiE.hN7-Yixe1m939BtYdGoFuEjZqAQubrs1bRqOEjDl1Lo&dib_tag=se&keywords=arduino+switch+button&qid=1726854729&sr=8-4)
- 1 [slide switch](https://www.amazon.com/Switch-SPDT-Micro-Breadboard-GuuYebe/dp/B0CRTPY88B/ref=sr_1_3?crid=27IWAPGXO1MMZ&dib=eyJ2IjoiMSJ9._ATEYuexpE4s6ZcRyDLfSCIAKh3bQiL95u7dTJn1UZ3y-SyFXw_BWVaa-FGQnrS6WE80pijUw7gkZrPlhPRIMHo8EBgC5LultrwsaGZ10pqGfQux0IcFpM0xNXPT_GRIjSpIEyMumHAoyfS2PAOeloukHnSPFlOKWxSEknA92bXF8nBvqzv7Mu8ecQL26Mo83bwqqC8etpcB-qd6Sg1EUvPvfrCekfO2Rxryvv4jWfc.oILbK06wLiG_KIEUB6fNbI9Tl4Fi1qLnr4_YWiLklDg&dib_tag=se&keywords=breadboard+toggle+switch&qid=1726950909&sprefix=breadboard+toggle+switc%2Caps%2C187&sr=8-3)
- [Breadboard jumper wires](https://www.amazon.com/Breadboard-Minidodoca-Magnetic-Assortment-Alligator/dp/B0BFX352X6/ref=asc_df_B0BT82DH1Q/?tag=hyprod-20&linkCode=df0&hvadid=693270340266&hvpos=&hvnetw=g&hvrand=16202308993735360576&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9051751&hvtargid=pla-2062059538455&mcid=e6a607cfb9973276bcafccc1d8dc0e4f&th=1)
- 1 [4 AA battery holder](https://www.amazon.com/LAMPVPATH-Battery-Holder-Bundle-Arduino/dp/B07BNN9PDF/ref=sr_1_1?crid=2HM5F0TK6SDRY&dib=eyJ2IjoiMSJ9.RTC14PQvxjhth6XIjocUZouOb8Sh2Ud3DFB-Q8NwKyJPZzmZ64Zq0juBxD19TY9BZnB8OqvFqBFjUd9oyHUt2ZApQfPLSJ8F18LJcord1M5nyfLKrYyi2QIYc4-vlM0V_YcK-7MsTtE0IAPJSxPKH_A0I9vvefnEHwZBBgBdZJ1AW2NZqwdTKpFlnwZlgX2ozD5NeHvLF40ftIvtQHmLaovXmI8T127YAPe9ROILK3F2d2VxI8IzOLG0crN3rqQMXUm9dkXiHG-GtW3XyBLuHEJ7WkdUUhB5Xv_8D-BM13k.Cv-COviu4b6XMDpgZ3L19hWi4Yz-v0sSkiJUcchOzYE&dib_tag=se&keywords=arduino+AAbattery+holder&qid=1726951550&s=electronics&sprefix=arduino+aabattery+holder%2Celectronics%2C186&sr=1-1)
- Breadboard
- Earbuds
- PLA Filament
