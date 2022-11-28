# Finding Feature

## KeyPoint(Сонирхолын цэг)

"keypoints" = "interest points", зарим үед 
"features" гэж нэрлэдэг

`Interest points:` хараглзах цэгүүдийг олоход хамгийн хэрэгтэй арга.

### Булан (Corners) гэж юу вэ?

* Ирмэгийн уулзвар

* Илүү тогтвортой feature

* Бүх чиглэлдээ хөрш цэгүүдээс огцом өөрчлөлттэй байдаг

* Match хийхэд хамгийн сайн feature байдаг.

### Motivation: Matching Problem

Стерио болон хөдөлгөөнийг тооцоолох Vision таскууд нь хоёр ба хэд хэдэн харагдацын тохирох feature олох шаардлага тулгардаг.

### KeyPoint (Сонирхолын цэг)

`Correspondence: ` matching, points, patches, edges, or region s across images

`Alignment: ` solving the transformation that makes two things match better

### Motivation: Patch Matching

Match хийх элементүүд нь тодорхой хэмжээтэй зургийн patches байна.


patches бүгдээрээ тэнцүү биш байна.

### Хэрэглээ 

`tracking: ` which points are good to track?
`recognition: ` find patches likely to tell us something about object category
`3D reconstruction: ` find corresspondences across different views

### Keypoint Matching 

1. Онцлог гол цэгүүдийг олох 

2. Гол цэгүүдийн эргэн тойрон дахь мужыг тодорхойлох

3. Контентуудыг нормчлох, гарган авах

4. Нормчлогдсоан мужын локал тодорхойлох ойлгогчийг тооцоолох 

5. Локал тодорхойлохгчийг холбох

### Keypoints зорилго

дахин давтагдах, ялгаатай цэгүүдийг илрүүлэх 

### Илрүүлэлтийн аргууд

`Hession & Harris` 
`Leplacian, DoG`
`Harris-/Hessian-Laplace`
`Harris-/Hessian-Affine`
`EBR and IBR`
`MSER`
`Salient Regions`
`Others....`

### KeyPoint Localization 

* Зорилго 

- Repeatable detection

- Precise localization

- Interesting content

### Сонирхолын цэг болох Булан (Corners as Distinctive Interest Points)

* Загварчлалын шалгуурууд 

	- smal window (locality) харвал бид цэгийг амархан таних ёстой.

	- windows аль ч чиглэлэд шилжүүлсэн эрчимд (intensity) том өөрчлөлт авчирдаг байх ёстой (good localization)

	"flat" region: no change in all directions

	"edge": no change edge direction

	"corner": significant change in all directions

## Гол цэгийн локачлал (Keypoint Localization) 

### Harris илрүүлэгч

Harris илрүүлэгч хэрэв windows (w) зураг дээгүүр шилжиж байвал шилжилтээс үүдэлтэй пикселийн утгуудын эрчимийн өөрчлөлт булангууд дээр өндөр бөйна гэж үзнэ. Учир нь пикселийн эрчим өөрчлөгдөх нь булан бүрт (x ба у) хоёр чиглэлд ажигллагддаг бол ирмэг дээр зөвхөн нэг чиглэлээр хязгаарлагда тул хавтгай (flat) зургийн мужуудад ач холбогдолгүй юм. Шилжилтийн [u, v] улмаас эрчимийн өөрчлөлтйиг тооцоолохдоо: 

Булангуудыг олохын тулд энэ функцийн хамгийн дээд хэмжээнд байлгах ёстой. Тейлорын өргөтгөл (Taylor Expansion) нь дараах тэгшитгэлийг авах үйл явцад ашиглдаг:













