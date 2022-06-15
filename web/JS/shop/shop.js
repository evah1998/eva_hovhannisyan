alert(`1․ Սնիկերս - 200դր,
2․ Կոլա - 400դր,
3․ Ջերմուկ - 99.9դր
4. Շոկոլադ - 1200դր,
5. Կոնֆետ - 350դր`
)
const snickersPrice = 200;
const colaPrice = 400;
const jermukPrice = 99.9;
const chocolatePrice = 1200;
const candyPrice = 350;

const snickersCount = prompt ("Սնիկերսի քանակը", "0");
const colaCount = prompt ("Կոլայի քանակը", "0");
const jermukCount = prompt ("Ջերմուկի քանակը", "0");
const chocolateCount = prompt ("Շոկոլադի քանակը", "0");
const candyCount = prompt ("Կոնֆետի քանակը", "0");

const snickersValue = snickersCount * snickersPrice;
const colaValue = colaCount * colaPrice;
const jermukValue = jermukCount * jermukPrice;
const chocolateValue = chocolateCount * chocolatePrice;
const candyValue = candyCount * candyPrice;

function totalValue() {
    return snickersValue + colaValue + jermukValue + chocolateValue + candyValue;
}

if (totalValue() === 0) {
    console.log('Դուք ոչինչ չեք գնել');
} else {
    const amountPaid = prompt(`Պետք է վճարեք ${totalValue()}`, 0 );
    const returnedMoney = amountPaid - totalValue();
    if (amountPaid == 0) {
        console.log('Սխալ գումարի մուտք');
    } else if (totalValue() > amountPaid) {
        console.log('Ձեր գումարը բավարար չէ գնումներ կատարելու համար');
    } else {
    console.log(`Ընդամենը: ${amountPaid}, 
Վերադարձ։ ${returnedMoney},
Ծախս։ ${totalValue()}`);
    if (snickersCount > 0) console.log(`Սնիկերս - ${snickersCount} հատ - ${snickersValue}դր`);
    if (colaCount > 0) console.log(`Կոլա - ${colaCount} հատ - ${colaValue}դր`);
    if (jermukCount > 0) console.log(`Ջերմուկ - ${jermukCount} հատ - ${jermukValue}դր`);
    if (chocolateCount > 0) console.log(`Շոկոլադ - ${chocolateCount} հատ - ${chocolateValue}դր`);
    if (candyCount > 0) console.log(`Կոնֆետ - ${candyCount} հատ - ${candyValue}դր`);
    }
}