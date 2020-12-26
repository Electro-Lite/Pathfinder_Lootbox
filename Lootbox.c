#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int TabC;
enum Material5_6 {STEEL, WOODANDSTEEL, WOOD};
enum Material5_7 {METALS,DRAGONHIDE,DRAGONHIDEANDMETALS};
enum Material5_15 {/*METALS*/WOODANDMETALS=1/*WOOD*/};
enum MagicType {DIVINE, ARCANE};
typedef struct {
  char title[10][25];
  int rolls[10];
  char description[100];
} Item_st;
int FindSpot(Item_st *Item){
  int Adjective=8;
  while (strlen(Item->title[Adjective])>1) {
    Adjective--;
    if(Adjective<0){printf(" no free Adjective spot\n");break;}
  }
  return Adjective;
}
int table6_9(int Price){
  int roll;
  char PriceLess10[85][30]={
    {"Backpack (empty"},
    {"Barrel (empty)"},
    {"Basket (empty)"},
    {"Bedroll"},
    {"Bell"},
    {"Blanket, winter"},
    {"Block and tackle"},
    {"Bottle, glass"},
    {"Bucket (empty)"},
    {"Caltrops"},
    {"Candle"},
    {"Canvas (sq. yd.)"},
    {"Case, map or scroll"},
    {"Chain (10 ft."},
    {"Chalk, 1 piece"},
    {"Chest (empty)"},
    {"Crowbar"},
    {"Firewood (per day)"},
    {"Fishhook"},
    {"Fishing net, 25 sq. ft"},
    {"Flask (empty)"},
    {"Flint and steel"},
    {"Grappling hook"},
    {"Hammer"},
    {"Hourglass"},
    {"Ink (1 oz. vial)"},
    {"Inkpen"},
    {"Jug, clay"},
    {"Ladder, 10-foot"},
    {"Lamp, common"},
    {"Lantern, hooded"},
    {"Oil (1-pint flask)"},
    {"Mug/Tankard, clay"},
    {"Paper (sheet"},
    {"Parchment (sheet)"},
    {"Pick, miner’s"},
    {"Pitcher, clay"},
    {"Piton"},
    {"Pole, 10-foot"},
    {"Pot, iron"},
    {"Pouch, belt (empty)"},
    {"Rations(2days)"},
    {"Rope, hemp (50 ft.)"},
    {"Sack (empty) "},
    {"Sealing wax"},
    {"Sewing needle"},
    {"Shovel or spade"},
    {"Signal whistle"},
    {"Signet ring"},
    {"Sledge"},
    {"Soap (per lb.)"},
    {"Torch"},
    {"Vial, ink or potion"},
    {"Waterskin"},
    {"Whetstone"},
    {"Sunrod"},
    {"Tindertwig"},
    {"Artisan’s tools"},
    {"Holy symbol, wooden"},
    {"Musical instrument, common"},
    {"Scale, merchant’s"},
    {"Spell component pouch"},
    {"Artisan’s outfit"},
    {"Cleric’s vestments"},
    {"Cold-weather outfit"},
    {"Entertainer’s outfit"},
    {"Monk’s outfit"},
    {"Peasant’s outfit"},
    {"Scholar’s outfit"},
    {"Traveler’s outfit"},
    {"Gallon of ale"},
    {"Mug of ale"},
    {"Bread, loaf of"},
    {"Cheese, hunk of"},
    {"Good meal"},
    {"Common meal"},
    {"Poor meal"},
    {"Meat, chunk of"},
    {"Wine common (pitcher) "},
    {"Bit and bridle"},
    {"Donkey or mule"},
    {"Feed for animal (1day)"},
    {"Oar"},
    {"Pack saddle"},
    {"Saddlebags"},
  };
  char PriceLess50[27][30]={
    {"Chain (10 ft.)"},
    {"Simple lock"},
    {"Manacles"},
    {"Ram, portable"},
    {"Rope, silk (50 ft.)"},
    {"Tent"},
    {"Acid (flask)"},
    {"Alchemist’s fire (flask)"},
    {"Holy water (flask)"},
    {"Thunderstone"},
    {"Holy symbol, silver"},
    {"Spellbook, wizard’s (blank)"},
    {"Thieves’ tools"},
    {"Courtier’s outfit"},
    {"Explorer’s outfit"},
    {"Banquet (=much food)"},
    {"Wine fine (bottle)"},
    {"Dog, guard"},
    {"Pony (no combat training)"},
    {"Pony (combat trained)"},
    {"Military saddle"},
    {"Riding saddle"},
    {"Exotic pack saddle"},
    {"Exotic riding saddle"},
    {"Cart"},
    {"Sled"},
    {"Wagon"},
  };
  char PriceLess100[13][30]={
    {"Good lock"},
    {"Manacles, masterwork"},
    {"Antitoxin (vial)"},
    {"Tanglefoot bag"},
    {"Artisan’s tools, masterwork"},
    {"Climber’s kit"},
    {"Disguise kit"},
    {"Healer’s kit"},
    {"Tool, masterwork"},
    {"Noble’s outfit"},
    {"Horse, light"},
    {"Exotic military saddle"},
    {"Rowboat"},
  };
  char Priceover100[20][40]={
    {"Superior lock"},
    {"Spyglass"},
    {"Water clock"},
    {"Everburning torch"},
    {"Alchemist’s lab"},
    {"Magnifying glass"},
    {"Musical instrument, masterwork"},
    {"Thieves’ tools, masterwork"},
    {"Royal outfit"},
    {"Dog, riding"},
    {"Horse, heavy (not combat trained)"},
    {"Horse, heavy (combat trained)"},
    {"Horse, light (combat trained)"},
    {"Carriage"},
    {"Galley"},
    {"Keelboat"},
    {"Longship"},
    {"Sailing ship"},
    {"Warship"},
  };
  if     (Price<10){printf("%roll d85\n");scanf("%d",&roll);printf("%s\n",PriceLess10[roll]);}
  else if(Price<50){printf("%roll d27\n");scanf("%d",&roll);printf("%s\n",PriceLess50[roll]);}
  else if(Price<100){printf("%roll d13\n");scanf("%d",&roll);printf("%s\n",PriceLess100[roll]);}
  else /*over 100*/ {printf("%roll d20\n");scanf("%d",&roll);printf("%s\n",Priceover100[roll]);}
  return 0;
}
void Table5_7(Item_st *Item,int BaseMat){
  int Adjective=FindSpot(Item);
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(BaseMat==0){
    if(roll<91){return;}
    else if(roll<96){strcpy(Item->title[Adjective],"Dragonhide");}
    else if(roll>=96){strcpy(Item->title[Adjective],"Mithral");}
  }
  else if(BaseMat==1){
    if(roll<91){return;}
    else if(roll<96){strcpy(Item->title[Adjective],"Darkwood");}
    else if(roll>=96){strcpy(Item->title[Adjective],"Mithral");}
  }
  else if(BaseMat==2){
    if(roll<91){return;}
    else if(roll>=91){strcpy(Item->title[Adjective],"Darkwood");}
  }
  return;
}
void Table5_6(Item_st *Item,int BaseMat){
  int Adjective=FindSpot(Item);
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(BaseMat==0){
    if(roll<91){return;}
    else if(roll<98){strcpy(Item->title[Adjective],"Adamantine");}
    else if(roll>=98){strcpy(Item->title[Adjective],"Mithral");}
  }
  else if(BaseMat==1){
    if(roll<91){return;}
    else if(roll>=91){strcpy(Item->title[Adjective],"Dragonhide");}
  }
  else if(BaseMat==2){
    if(roll<91){return;}
    else if(roll<95){strcpy(Item->title[Adjective],"Adamantine");}
    else if(roll<99){strcpy(Item->title[Adjective],"Dragonhide");}
    else if(roll>=99){strcpy(Item->title[Adjective],"Mithral");}
  }
  return;
}
int Table5_3(Item_st *Item){
  int Adjective=FindSpot(Item);
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<6){strcpy(Item->title[9],"Padded armor");}
  else if(roll<14){strcpy(Item->title[9],"Leather armor");}
  else if(roll<23){strcpy(Item->title[9],"Studded leather armor");Table5_6(Item, METALS);}
  else if(roll<31){strcpy(Item->title[9],"Chain shirt");Table5_6(Item, METALS);}
  else if(roll<39){strcpy(Item->title[9],"Hide armor");Table5_6(Item, DRAGONHIDE);}
  else if(roll<47){strcpy(Item->title[9],"Scale mail");Table5_6(Item, METALS);}
  else if(roll<55){strcpy(Item->title[9],"Chainmail");Table5_6(Item, METALS);}
  else if(roll<63){strcpy(Item->title[9],"Breastplate");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<71){strcpy(Item->title[9],"Splint mail");Table5_6(Item, METALS);}
  else if(roll<79){strcpy(Item->title[9],"Banded mail");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<87){strcpy(Item->title[9],"Half-plate");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<95){strcpy(Item->title[9],"Full plate");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<98){strcpy(Item->title[Adjective],"Spiked");Table5_3(Item);}
  else if(roll>=98){strcpy(Item->title[Adjective],"With locked gauntlet");Table5_3(Item);}
  return 0;
}
int Table5_5(Item_st *Item){
  int Adjective=FindSpot(Item);
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<17){strcpy(Item->title[9],"Buckler");Table5_7(Item, STEEL);}
  else if(roll<33){strcpy(Item->title[9],"Light wooden shield");Table5_7(Item, WOOD);}
  else if(roll<49){strcpy(Item->title[9],"Light steel shield");Table5_7(Item, STEEL);}
  else if(roll<65){strcpy(Item->title[9],"Heavy wooden shield");Table5_7(Item, WOOD);}
  else if(roll<81){strcpy(Item->title[9],"Heavy steel shield");Table5_7(Item, STEEL);}
  else if(roll<96){strcpy(Item->title[9],"Tower shield");Table5_7(Item, WOODANDSTEEL);}
  else if(roll>=96){strcpy(Item->title[Adjective],"Spiked");Table5_5(Item);}

  return 0;
}
int Table5_4(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<56){Table5_3(Item);}
  else if(roll>=56){Table5_5(Item);}
  return 0;
}
void Table5_27(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<7){strcpy(Item->title[9],"acid splash");}
  else if(roll<11){strcpy(Item->title[9],"arcane mark");}
  else if(roll<14){strcpy(Item->title[9],"bleed");}
  else if(roll<19){strcpy(Item->title[9],"dancing lights");}
  else if(roll<24){strcpy(Item->title[9],"daze");}
  else if(roll<31){strcpy(Item->title[9],"detect magic");}
  else if(roll<38){strcpy(Item->title[9],"detect poison");}
  else if(roll<45){strcpy(Item->title[9],"disrupt undead");}
  else if(roll<49){strcpy(Item->title[9],"flare");}
  else if(roll<53){strcpy(Item->title[9],"ghost sound");}
  else if(roll<59){strcpy(Item->title[9],"light");}
  else if(roll<63){strcpy(Item->title[9],"mage hand");}
  else if(roll<69){strcpy(Item->title[9],"mending");}
  else if(roll<77){strcpy(Item->title[9],"message");}
  else if(roll<80){strcpy(Item->title[9],"open/close");}
  else if(roll<83){strcpy(Item->title[9],"prestidigitation");}
  else if(roll<89){strcpy(Item->title[9],"ray of frost");}
  else if(roll<92){strcpy(Item->title[9],"read magic");}
  else if(roll<96){strcpy(Item->title[9],"resistance");}
  else if(roll>=96){strcpy(Item->title[9],"touch of fatigue");}

  return;
}
void Table5_28(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"alarm");}
  else if(roll<4){strcpy(Item->title[9],"animate rope");}
  else if(roll<7){strcpy(Item->title[9],"burning hands");}
  else if(roll<10){strcpy(Item->title[9],"cause fear");}
  else if(roll<12){strcpy(Item->title[9],"charm person");}
  else if(roll<15){strcpy(Item->title[9],"chill touch");}
  else if(roll<17){strcpy(Item->title[9],"color spray");}
  else if(roll<20){strcpy(Item->title[9],"comprehend languages");}
  else if(roll<23){strcpy(Item->title[9],"detect secret doors");}
  else if(roll<26){strcpy(Item->title[9],"detect undead");}
  else if(roll<29){strcpy(Item->title[9],"disguise self");}
  else if(roll<32){strcpy(Item->title[9],"endure elements");}
  else if(roll<34){strcpy(Item->title[9],"enlarge person");}
  else if(roll<35){strcpy(Item->title[9],"erase");}
  else if(roll<38){strcpy(Item->title[9],"expeditious retreat");}
  else if(roll<40){strcpy(Item->title[9],"floating disk");}
  else if(roll<43){strcpy(Item->title[9],"grease");}
  else if(roll<44){strcpy(Item->title[9],"hold portal");}
  else if(roll<47){strcpy(Item->title[9],"hypnotism");}
  else if(roll<50){strcpy(Item->title[9],"identify");}
  else if(roll<52){strcpy(Item->title[9],"jump");}
  else if(roll<55){strcpy(Item->title[9],"mage armor");}
  else if(roll<56){strcpy(Item->title[9],"magic aura");}
  else if(roll<59){strcpy(Item->title[9],"magic missile");}
  else if(roll<62){strcpy(Item->title[9],"magic weapon");}
  else if(roll<64){strcpy(Item->title[9],"mount");}
  else if(roll<67){strcpy(Item->title[9],"obscuring mist");}
  else if(roll<69){strcpy(Item->title[9],"protection from chaos");}
  else if(roll<71){strcpy(Item->title[9],"protection from evil");}
  else if(roll<73){strcpy(Item->title[9],"protection from good");}
  else if(roll<75){strcpy(Item->title[9],"protection from law");}
  else if(roll<77){strcpy(Item->title[9],"ray of enfeeblement");}
  else if(roll<79){strcpy(Item->title[9],"reduce person");}
  else if(roll<82){strcpy(Item->title[9],"shield");}
  else if(roll<85){strcpy(Item->title[9],"shocking grasp");}
  else if(roll<88){strcpy(Item->title[9],"silent image");}
  else if(roll<91){strcpy(Item->title[9],"sleep");}
  else if(roll<94){strcpy(Item->title[9],"summon monster I");}
  else if(roll<97){strcpy(Item->title[9],"true strike");}
  else if(roll<99){strcpy(Item->title[9],"unseen servant");}
  else if(roll>=99){strcpy(Item->title[9],"ventriloquism");}

  return;
}
void Table5_29(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"acid arrow");}
  else if(roll<5){strcpy(Item->title[9],"alter self");}
  else if(roll<7){strcpy(Item->title[9],"bear's endurance");}
  else if(roll<9){strcpy(Item->title[9],"blindness-deafness");}
  else if(roll<11){strcpy(Item->title[9],"blur");}
  else if(roll<13){strcpy(Item->title[9],"bull's strength");}
  else if(roll<15){strcpy(Item->title[9],"cat's grace");}
  else if(roll<17){strcpy(Item->title[9],"command undead");}
  else if(roll<19){strcpy(Item->title[9],"darkness");}
  else if(roll<21){strcpy(Item->title[9],"darkvision");}
  else if(roll<22){strcpy(Item->title[9],"daze monster");}
  else if(roll<23){strcpy(Item->title[9],"detect thoughts");}
  else if(roll<25){strcpy(Item->title[9],"eagle's splendor");}
  else if(roll<27){strcpy(Item->title[9],"false life");}
  else if(roll<29){strcpy(Item->title[9],"flaming sphere");}
  else if(roll<31){strcpy(Item->title[9],"fog cloud");}
  else if(roll<33){strcpy(Item->title[9],"fox's cunning");}
  else if(roll<35){strcpy(Item->title[9],"ghoul touch");}
  else if(roll<38){strcpy(Item->title[9],"glitterdust");}
  else if(roll<40){strcpy(Item->title[9],"gust of wind");}
  else if(roll<42){strcpy(Item->title[9],"hideous laughter");}
  else if(roll<44){strcpy(Item->title[9],"hypnotic pattern");}
  else if(roll<47){strcpy(Item->title[9],"invisibility");}
  else if(roll<50){strcpy(Item->title[9],"knock");}
  else if(roll<53){strcpy(Item->title[9],"levitate");}
  else if(roll<54){strcpy(Item->title[9],"locate object");}
  else if(roll<55){strcpy(Item->title[9],"make whole");}
  else if(roll<57){strcpy(Item->title[9],"minor image");}
  else if(roll<60){strcpy(Item->title[9],"mirror image");}
  else if(roll<62){strcpy(Item->title[9],"misdirection");}
  else if(roll<63){strcpy(Item->title[9],"obscure object");}
  else if(roll<64){strcpy(Item->title[9],"owl's wisdom");}
  else if(roll<66){strcpy(Item->title[9],"protection from arrows");}
  else if(roll<68){strcpy(Item->title[9],"pyrotechnics");}
  else if(roll<70){strcpy(Item->title[9],"resist energy");}
  else if(roll<73){strcpy(Item->title[9],"rope trick");}
  else if(roll<74){strcpy(Item->title[9],"scare");}
  else if(roll<77){strcpy(Item->title[9],"scorching ray");}
  else if(roll<80){strcpy(Item->title[9],"see invisibility");}
  else if(roll<82){strcpy(Item->title[9],"shatter");}
  else if(roll<83){strcpy(Item->title[9],"spectral hand");}
  else if(roll<86){strcpy(Item->title[9],"spider climb");}
  else if(roll<88){strcpy(Item->title[9],"summon monster II");}
  else if(roll<90){strcpy(Item->title[9],"summon swarm");}
  else if(roll<92){strcpy(Item->title[9],"touch of idiocy");}
  else if(roll<94){strcpy(Item->title[9],"web");}
  else if(roll<97){strcpy(Item->title[9],"whispering wind");}
  else if(roll<98){strcpy(Item->title[9],"magic mouth");}
  else if(roll<99){strcpy(Item->title[9],"arcane lock");}
  else if(roll<100){strcpy(Item->title[9],"continual flame");}
  else if(roll>=100){strcpy(Item->title[9],"phantom trap");}
  return;
}
void Table5_30(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"arcane sight");}
  else if(roll<4){strcpy(Item->title[9],"beast shape");}
  else if(roll<7){strcpy(Item->title[9],"blink");}
  else if(roll<8){strcpy(Item->title[9],"clairaudience/clairvoyance");}
  else if(roll<10){strcpy(Item->title[9],"daylight");}
  else if(roll<12){strcpy(Item->title[9],"deep slumber");}
  else if(roll<16){strcpy(Item->title[9],"dispel magic");}
  else if(roll<17){strcpy(Item->title[9],"displacement");}
  else if(roll<18){strcpy(Item->title[9],"explosive runes");}
  else if(roll<22){strcpy(Item->title[9],"fireball");}
  else if(roll<24){strcpy(Item->title[9],"flame arrow");}
  else if(roll<27){strcpy(Item->title[9],"fly");}
  else if(roll<30){strcpy(Item->title[9],"gaseous form");}
  else if(roll<31){strcpy(Item->title[9],"gentle repose");}
  else if(roll<33){strcpy(Item->title[9],"halt undead");}
  else if(roll<36){strcpy(Item->title[9],"haste");}
  else if(roll<37){strcpy(Item->title[9],"heroism");}
  else if(roll<40){strcpy(Item->title[9],"hold person");}
  else if(roll<43){strcpy(Item->title[9],"invisibility sphere");}
  else if(roll<44){strcpy(Item->title[9],"keen edge");}
  else if(roll<47){strcpy(Item->title[9],"lightning bolt");}
  else if(roll<49){strcpy(Item->title[9],"magic circle against chaos");}
  else if(roll<51){strcpy(Item->title[9],"magic circle against evil");}
  else if(roll<53){strcpy(Item->title[9],"magic circle against good");}
  else if(roll<55){strcpy(Item->title[9],"magic circle against law");}
  else if(roll<56){strcpy(Item->title[9],"magic weapon, greater");}
  else if(roll<58){strcpy(Item->title[9],"major image");}
  else if(roll<61){strcpy(Item->title[9],"phantom steed");}
  else if(roll<64){strcpy(Item->title[9],"protection from energy");}
  else if(roll<65){strcpy(Item->title[9],"rage");}
  else if(roll<68){strcpy(Item->title[9],"ray of exhaustion");}
  else if(roll<70){strcpy(Item->title[9],"secret page");}
  else if(roll<71){strcpy(Item->title[9],"shrink item");}
  else if(roll<73){strcpy(Item->title[9],"sleet storm");}
  else if(roll<76){strcpy(Item->title[9],"slow");}
  else if(roll<77){strcpy(Item->title[9],"stinking cloud");}
  else if(roll<79){strcpy(Item->title[9],"suggestion");}
  else if(roll<82){strcpy(Item->title[9],"summon monster III");}
  else if(roll<85){strcpy(Item->title[9],"tiny hut");}
  else if(roll<87){strcpy(Item->title[9],"tongues");}
  else if(roll<90){strcpy(Item->title[9],"vampiric touch");}
  else if(roll<92){strcpy(Item->title[9],"water breathing");}
  else if(roll<94){strcpy(Item->title[9],"wind wall");}
  else if(roll<96){strcpy(Item->title[9],"illusory script");}
  else if(roll<98){strcpy(Item->title[9],"nondetection");}
  else if(roll>=98){strcpy(Item->title[9],"sepia snake sigil");}
  return;
}
void Table5_31(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"arcane eye");}
  else if(roll<5){strcpy(Item->title[9],"beast shape I");}
  else if(roll<8){strcpy(Item->title[9],"bestow curse");}
  else if(roll<10){strcpy(Item->title[9],"black tentacles");}
  else if(roll<13){strcpy(Item->title[9],"charm monster");}
  else if(roll<17){strcpy(Item->title[9],"confusion");}
  else if(roll<19){strcpy(Item->title[9],"contagion");}
  else if(roll<21){strcpy(Item->title[9],"crushing despair");}
  else if(roll<22){strcpy(Item->title[9],"detect scrying");}
  else if(roll<26){strcpy(Item->title[9],"dimension door");}
  else if(roll<30){strcpy(Item->title[9],"dimensional anchor");}
  else if(roll<32){strcpy(Item->title[9],"elemental body I");}
  else if(roll<35){strcpy(Item->title[9],"enervation");}
  else if(roll<37){strcpy(Item->title[9],"enlarge person, mass");}
  else if(roll<39){strcpy(Item->title[9],"fear");}
  else if(roll<41){strcpy(Item->title[9],"fire shield");}
  else if(roll<44){strcpy(Item->title[9],"geas, lesser");}
  else if(roll<47){strcpy(Item->title[9],"globe of invulnerability, lesser");}
  else if(roll<48){strcpy(Item->title[9],"hallucinatory terrain");}
  else if(roll<51){strcpy(Item->title[9],"ice storm");}
  else if(roll<52){strcpy(Item->title[9],"illusory wall");}
  else if(roll<56){strcpy(Item->title[9],"invisibility, greater");}
  else if(roll<57){strcpy(Item->title[9],"locate creature");}
  else if(roll<58){strcpy(Item->title[9],"minor creation");}
  else if(roll<60){strcpy(Item->title[9],"phantasmal killer");}
  else if(roll<62){strcpy(Item->title[9],"rainbow pattern");}
  else if(roll<64){strcpy(Item->title[9],"reduce person, mass");}
  else if(roll<65){strcpy(Item->title[9],"remove curse");}
  else if(roll<67){strcpy(Item->title[9],"resilient sphere");}
  else if(roll<69){strcpy(Item->title[9],"scrying");}
  else if(roll<71){strcpy(Item->title[9],"secure shelter");}
  else if(roll<73){strcpy(Item->title[9],"shadow conjuration");}
  else if(roll<75){strcpy(Item->title[9],"shout");}
  else if(roll<78){strcpy(Item->title[9],"solid fog");}
  else if(roll<80){strcpy(Item->title[9],"stone shape");}
  else if(roll<82){strcpy(Item->title[9],"summon monster IV");}
  else if(roll<85){strcpy(Item->title[9],"wall of fire");}
  else if(roll<88){strcpy(Item->title[9],"wall of ice");}
  else if(roll<92){strcpy(Item->title[9],"fire trap");}
  else if(roll<96){strcpy(Item->title[9],"mnemonic enhancer");}
  else if(roll<98){strcpy(Item->title[9],"stoneskin");}
  else if(roll>=98){strcpy(Item->title[9],"animate dead");}
  return;
}
void Table5_32(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<2){strcpy(Item->title[9],"animal growth");}
  else if(roll<6){strcpy(Item->title[9],"baleful polymorph");}
  else if(roll<8){strcpy(Item->title[9],"beast shape III");}
  else if(roll<9){strcpy(Item->title[9],"blight");}
  else if(roll<11){strcpy(Item->title[9],"break enchantment");}
  else if(roll<15){strcpy(Item->title[9],"cloudkill");}
  else if(roll<18){strcpy(Item->title[9],"cone of cold");}
  else if(roll<21){strcpy(Item->title[9],"contact other plane");}
  else if(roll<23){strcpy(Item->title[9],"dismissal");}
  else if(roll<26){strcpy(Item->title[9],"dominate person");}
  else if(roll<28){strcpy(Item->title[9],"dream");}
  else if(roll<29){strcpy(Item->title[9],"elemental body");}
  else if(roll<30){strcpy(Item->title[9],"fabricate");}
  else if(roll<32){strcpy(Item->title[9],"feeblemind");}
  else if(roll<35){strcpy(Item->title[9],"hold monster");}
  else if(roll<36){strcpy(Item->title[9],"interposing hand");}
  else if(roll<38){strcpy(Item->title[9],"mage's faithful hound");}
  else if(roll<40){strcpy(Item->title[9],"mage's private sanctum");}
  else if(roll<43){strcpy(Item->title[9],"magic jar");}
  else if(roll<44){strcpy(Item->title[9],"major creation");}
  else if(roll<46){strcpy(Item->title[9],"mind fog");}
  else if(roll<47){strcpy(Item->title[9],"mirage arcana");}
  else if(roll<49){strcpy(Item->title[9],"nightmare");}
  else if(roll<51){strcpy(Item->title[9],"overland flight");}
  else if(roll<53){strcpy(Item->title[9],"passwall");}
  else if(roll<55){strcpy(Item->title[9],"permanency");}
  else if(roll<56){strcpy(Item->title[9],"persistent image");}
  else if(roll<59){strcpy(Item->title[9],"planar binding, lesser");}
  else if(roll<60){strcpy(Item->title[9],"plant shape I");}
  else if(roll<63){strcpy(Item->title[9],"polymorph");}
  else if(roll<65){strcpy(Item->title[9],"prying eyes");}
  else if(roll<66){strcpy(Item->title[9],"secret chest");}
  else if(roll<67){strcpy(Item->title[9],"seeming");}
  else if(roll<70){strcpy(Item->title[9],"sending");}
  else if(roll<73){strcpy(Item->title[9],"shadow evocation");}
  else if(roll<76){strcpy(Item->title[9],"summon monster V");}
  else if(roll<79){strcpy(Item->title[9],"telekinesis");}
  else if(roll<80){strcpy(Item->title[9],"telepathic bond");}
  else if(roll<84){strcpy(Item->title[9],"teleport");}
  else if(roll<85){strcpy(Item->title[9],"transmute mud to rock");}
  else if(roll<86){strcpy(Item->title[9],"transmute rock to mud");}
  else if(roll<89){strcpy(Item->title[9],"wall of force");}
  else if(roll<91){strcpy(Item->title[9],"wall of stone");}
  else if(roll<93){strcpy(Item->title[9],"waves of fatigue");}
  else if(roll<95){strcpy(Item->title[9],"false vision");}
  else if(roll<98){strcpy(Item->title[9],"symbol of pain");}
  else if(roll>=98){strcpy(Item->title[9],"symbol of sleep");}
  return;
}
void Table5_33(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"acid fog");}
  else if(roll<5){strcpy(Item->title[9],"analyze dweomer");}
  else if(roll<8){strcpy(Item->title[9],"antimagic field");}
  else if(roll<10){strcpy(Item->title[9],"bear's endurance, mass");}
  else if(roll<11){strcpy(Item->title[9],"beast shape IV");}
  else if(roll<13){strcpy(Item->title[9],"bull's strength, mass");}
  else if(roll<15){strcpy(Item->title[9],"cat's grace, mass");}
  else if(roll<18){strcpy(Item->title[9],"chain lightning");}
  else if(roll<20){strcpy(Item->title[9],"contingency");}
  else if(roll<21){strcpy(Item->title[9],"control water");}
  else if(roll<25){strcpy(Item->title[9],"disintegrate");}
  else if(roll<29){strcpy(Item->title[9],"dispel magic, greater");}
  else if(roll<31){strcpy(Item->title[9],"eagle's splendor, mass ");}
  else if(roll<32){strcpy(Item->title[9],"elemental body III");}
  else if(roll<34){strcpy(Item->title[9],"eyebite");}
  else if(roll<37){strcpy(Item->title[9],"flesh to stone");}
  else if(roll<39){strcpy(Item->title[9],"forceful hand");}
  else if(roll<41){strcpy(Item->title[9],"form of the dragon I");}
  else if(roll<43){strcpy(Item->title[9],"fox's cunning, mass");}
  else if(roll<44){strcpy(Item->title[9],"freezing sphere");}
  else if(roll<46){strcpy(Item->title[9],"geas/quest");}
  else if(roll<49){strcpy(Item->title[9],"globe of invulnerability");}
  else if(roll<51){strcpy(Item->title[9],"guards and wards");}
  else if(roll<53){strcpy(Item->title[9],"heroism, greater");}
  else if(roll<55){strcpy(Item->title[9],"mage's lucubration");}
  else if(roll<58){strcpy(Item->title[9],"mislead");}
  else if(roll<59){strcpy(Item->title[9],"move earth");}
  else if(roll<60){strcpy(Item->title[9],"owl's wisdom, mass");}
  else if(roll<62){strcpy(Item->title[9],"permanent image");}
  else if(roll<65){strcpy(Item->title[9],"planar binding");}
  else if(roll<66){strcpy(Item->title[9],"plant shape II");}
  else if(roll<68){strcpy(Item->title[9],"repulsion");}
  else if(roll<70){strcpy(Item->title[9],"shadow walk");}
  else if(roll<72){strcpy(Item->title[9],"stone to flesh");}
  else if(roll<75){strcpy(Item->title[9],"suggestion, mass");}
  else if(roll<77){strcpy(Item->title[9],"summon monster VI");}
  else if(roll<79){strcpy(Item->title[9],"transformation");}
  else if(roll<82){strcpy(Item->title[9],"veil");}
  else if(roll<84){strcpy(Item->title[9],"programmed image");}
  else if(roll<86){strcpy(Item->title[9],"wall of iron");}
  else if(roll<88){strcpy(Item->title[9],"create undead");}
  else if(roll<90){strcpy(Item->title[9],"legend lore");}
  else if(roll<93){strcpy(Item->title[9],"true seeing");}
  else if(roll<96){strcpy(Item->title[9],"circle of death");}
  else if(roll<97){strcpy(Item->title[9],"undeath to death");}
  else if(roll<99){strcpy(Item->title[9],"symbol of fear");}
  else if(roll>=99){strcpy(Item->title[9],"symbol of persuasion");}
  return;
}
void Table5_34(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<4){strcpy(Item->title[9],"arcane sight, greater");}
  else if(roll<7){strcpy(Item->title[9],"banishment");}
  else if(roll<9){strcpy(Item->title[9],"control undead");}
  else if(roll<11){strcpy(Item->title[9],"control weather");}
  else if(roll<14){strcpy(Item->title[9],"delayed blast fireball");}
  else if(roll<16){strcpy(Item->title[9],"elemental body IV");}
  else if(roll<19){strcpy(Item->title[9],"ethereal jaunt");}
  else if(roll<23){strcpy(Item->title[9],"finger of death");}
  else if(roll<25){strcpy(Item->title[9],"form of the dragon II");}
  else if(roll<27){strcpy(Item->title[9],"giant form I");}
  else if(roll<29){strcpy(Item->title[9],"grasping hand");}
  else if(roll<32){strcpy(Item->title[9],"hold person, mass");}
  else if(roll<34){strcpy(Item->title[9],"insanity");}
  else if(roll<37){strcpy(Item->title[9],"invisibility, mass");}
  else if(roll<39){strcpy(Item->title[9],"mage's magnificent mansion");}
  else if(roll<41){strcpy(Item->title[9],"mage's sword");}
  else if(roll<43){strcpy(Item->title[9],"phase door");}
  else if(roll<46){strcpy(Item->title[9],"plane shift");}
  else if(roll<48){strcpy(Item->title[9],"plant shape III");}
  else if(roll<52){strcpy(Item->title[9],"polymorph, greater");}
  else if(roll<54){strcpy(Item->title[9],"power word blind");}
  else if(roll<57){strcpy(Item->title[9],"prismatic spray");}
  else if(roll<59){strcpy(Item->title[9],"reverse gravity");}
  else if(roll<62){strcpy(Item->title[9],"scrying, greater");}
  else if(roll<64){strcpy(Item->title[9],"sequester");}
  else if(roll<67){strcpy(Item->title[9],"shadow conjuration, greater");}
  else if(roll<70){strcpy(Item->title[9],"spell turning");}
  else if(roll<72){strcpy(Item->title[9],"statue");}
  else if(roll<75){strcpy(Item->title[9],"summon monster VII");}
  else if(roll<77){strcpy(Item->title[9],"teleport object");}
  else if(roll<81){strcpy(Item->title[9],"teleport, greater");}
  else if(roll<84){strcpy(Item->title[9],"waves of exhaustion");}
  else if(roll<86){strcpy(Item->title[9],"project image");}
  else if(roll<88){strcpy(Item->title[9],"vision");}
  else if(roll<91){strcpy(Item->title[9],"forcecage");}
  else if(roll<93){strcpy(Item->title[9],"instant summons");}
  else if(roll<95){strcpy(Item->title[9],"limited wish");}
  else if(roll<97){strcpy(Item->title[9],"symbol of stunning");}
  else if(roll<99){strcpy(Item->title[9],"symbol of weakness");}
  else if(roll>=99){strcpy(Item->title[9],"simulacrum");}
  return;
}
void Table5_35(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"antipathy");}
  else if(roll<6){strcpy(Item->title[9],"charm monster, mass");}
  else if(roll<8){strcpy(Item->title[9],"clenched fist");}
  else if(roll<10){strcpy(Item->title[9],"clone");}
  else if(roll<13){strcpy(Item->title[9],"demand");}
  else if(roll<17){strcpy(Item->title[9],"dimensional lock");}
  else if(roll<20){strcpy(Item->title[9],"discern location");}
  else if(roll<22){strcpy(Item->title[9],"form of the dragon III");}
  else if(roll<24){strcpy(Item->title[9],"giant form II");}
  else if(roll<27){strcpy(Item->title[9],"horrid wilting");}
  else if(roll<29){strcpy(Item->title[9],"incendiary cloud");}
  else if(roll<31){strcpy(Item->title[9],"iron body");}
  else if(roll<34){strcpy(Item->title[9],"irresistible dance");}
  else if(roll<38){strcpy(Item->title[9],"maze");}
  else if(roll<41){strcpy(Item->title[9],"mind blank");}
  else if(roll<43){strcpy(Item->title[9],"moment of prescience");}
  else if(roll<46){strcpy(Item->title[9],"planar binding, greater");}
  else if(roll<49){strcpy(Item->title[9],"polar ray");}
  else if(roll<53){strcpy(Item->title[9],"polymorph any object");}
  else if(roll<56){strcpy(Item->title[9],"power word stun");}
  else if(roll<59){strcpy(Item->title[9],"prismatic wall");}
  else if(roll<62){strcpy(Item->title[9],"prying eyes, greater");}
  else if(roll<65){strcpy(Item->title[9],"scintillating pattern");}
  else if(roll<67){strcpy(Item->title[9],"screen");}
  else if(roll<69){strcpy(Item->title[9],"shadow evocation, greater");}
  else if(roll<71){strcpy(Item->title[9],"shout, greater");}
  else if(roll<74){strcpy(Item->title[9],"summon monster VIII");}
  else if(roll<76){strcpy(Item->title[9],"sunburst");}
  else if(roll<80){strcpy(Item->title[9],"telekinetic sphere");}
  else if(roll<82){strcpy(Item->title[9],"create greater undead");}
  else if(roll<85){strcpy(Item->title[9],"protection from spells");}
  else if(roll<87){strcpy(Item->title[9],"sympathy");}
  else if(roll<90){strcpy(Item->title[9],"symbol of death");}
  else if(roll<92){strcpy(Item->title[9],"symbol of insanity");}
  else if(roll<96){strcpy(Item->title[9],"temporal stasis");}
  else if(roll<98){strcpy(Item->title[9],"binding (chaining)");}
  else if(roll>=98){strcpy(Item->title[9],"trap the soul");}
  return;
}
void Table5_36(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"crushing hand");}
  else if(roll<8){strcpy(Item->title[9],"dominate monster");}
  else if(roll<13){strcpy(Item->title[9],"energy drain");}
  else if(roll<17){strcpy(Item->title[9],"etherealness");}
  else if(roll<20){strcpy(Item->title[9],"foresight");}
  else if(roll<26){strcpy(Item->title[9],"freedom");}
  else if(roll<31){strcpy(Item->title[9],"gate");}
  else if(roll<34){strcpy(Item->title[9],"hold monster, mass");}
  else if(roll<38){strcpy(Item->title[9],"imprisonment");}
  else if(roll<44){strcpy(Item->title[9],"mage's disjunction");}
  else if(roll<52){strcpy(Item->title[9],"meteor swarm");}
  else if(roll<56){strcpy(Item->title[9],"power word kill");}
  else if(roll<59){strcpy(Item->title[9],"prismatic sphere");}
  else if(roll<62){strcpy(Item->title[9],"shades");}
  else if(roll<66){strcpy(Item->title[9],"shapechange");}
  else if(roll<68){strcpy(Item->title[9],"soul bind");}
  else if(roll<73){strcpy(Item->title[9],"summon monster IX");}
  else if(roll<79){strcpy(Item->title[9],"time stop");}
  else if(roll<82){strcpy(Item->title[9],"wail of the banshee");}
  else if(roll<86){strcpy(Item->title[9],"weird");}
  else if(roll<88){strcpy(Item->title[9],"refuge");}
  else if(roll<91){strcpy(Item->title[9],"astral projection");}
  else if(roll<95){strcpy(Item->title[9],"teleportation circle");}
  else if(roll>=95){strcpy(Item->title[9],"wish");}
  return;
}
void Table5_37(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<6){strcpy(Item->title[9],"bleed");}
  else if(roll<14){strcpy(Item->title[9],"create water");}
  else if(roll<24){strcpy(Item->title[9],"detect magic");}
  else if(roll<33){strcpy(Item->title[9],"detect poison");}
  else if(roll<38){strcpy(Item->title[9],"flare");}
  else if(roll<45){strcpy(Item->title[9],"guidance");}
  else if(roll<50){strcpy(Item->title[9],"know direction");}
  else if(roll<59){strcpy(Item->title[9],"light");}
  else if(roll<64){strcpy(Item->title[9],"mending");}
  else if(roll<72){strcpy(Item->title[9],"purify food and drink");}
  else if(roll<82){strcpy(Item->title[9],"read magic ");}
  else if(roll<87){strcpy(Item->title[9],"resistance");}
  else if(roll<95){strcpy(Item->title[9],"stabilize");}
  else if(roll>=95){strcpy(Item->title[9],"virtue");}
  return;
}
void Table5_38(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"bane");}
  else if(roll<6){strcpy(Item->title[9],"bless");}
  else if(roll<7){strcpy(Item->title[9],"calm animals");}
  else if(roll<11){strcpy(Item->title[9],"cause fear");}
  else if(roll<13){strcpy(Item->title[9],"charm animal");}
  else if(roll<16){strcpy(Item->title[9],"command");}
  else if(roll<19){strcpy(Item->title[9],"comprehend languages");}
  else if(roll<24){strcpy(Item->title[9],"cure light wounds");}
  else if(roll<26){strcpy(Item->title[9],"deathwatch");}
  else if(roll<27){strcpy(Item->title[9],"detect animals or plants");}
  else if(roll<29){strcpy(Item->title[9],"detect chaos");}
  else if(roll<31){strcpy(Item->title[9],"detect evil");}
  else if(roll<33){strcpy(Item->title[9],"detect good");}
  else if(roll<35){strcpy(Item->title[9],"detect law");}
  else if(roll<37){strcpy(Item->title[9],"detect snares and pits");}
  else if(roll<39){strcpy(Item->title[9],"detect undead");}
  else if(roll<41){strcpy(Item->title[9],"divine favor");}
  else if(roll<44){strcpy(Item->title[9],"doom");}
  else if(roll<46){strcpy(Item->title[9],"endure elements");}
  else if(roll<49){strcpy(Item->title[9],"entangle");}
  else if(roll<51){strcpy(Item->title[9],"entropic shield");}
  else if(roll<53){strcpy(Item->title[9],"faerie fire");}
  else if(roll<54){strcpy(Item->title[9],"goodberry");}
  else if(roll<55){strcpy(Item->title[9],"hide from animals");}
  else if(roll<57){strcpy(Item->title[9],"hide from undead");}
  else if(roll<59){strcpy(Item->title[9],"inflict light wounds");}
  else if(roll<61){strcpy(Item->title[9],"jump");}
  else if(roll<63){strcpy(Item->title[9],"longstrider");}
  else if(roll<66){strcpy(Item->title[9],"magic fang");}
  else if(roll<68){strcpy(Item->title[9],"magic stone");}
  else if(roll<71){strcpy(Item->title[9],"obscuring mist");}
  else if(roll<73){strcpy(Item->title[9],"pass without trace");}
  else if(roll<76){strcpy(Item->title[9],"produce flame");}
  else if(roll<78){strcpy(Item->title[9],"protection from chaos");}
  else if(roll<80){strcpy(Item->title[9],"protection from evil");}
  else if(roll<82){strcpy(Item->title[9],"protection from good");}
  else if(roll<84){strcpy(Item->title[9],"protection from law");}
  else if(roll<86){strcpy(Item->title[9],"remove fear");}
  else if(roll<88){strcpy(Item->title[9],"sanctuary");}
  else if(roll<91){strcpy(Item->title[9],"shield of faith");}
  else if(roll<92){strcpy(Item->title[9],"shillelagh");}
  else if(roll<94){strcpy(Item->title[9],"speak with animals");}
  else if(roll<96){strcpy(Item->title[9],"summon monster I");}
  else if(roll<98){strcpy(Item->title[9],"summon nature's ally I");}
  else if(roll<100){strcpy(Item->title[9],"bless water");}
  else if(roll>=100){strcpy(Item->title[9],"curse water");}
  return;
}
void Table5_39(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"aid");}
  else if(roll<6){strcpy(Item->title[9],"align weapon");}
  else if(roll<9){strcpy(Item->title[9],"animal messenger");}
  else if(roll<10){strcpy(Item->title[9],"animal trance");}
  else if(roll<14){strcpy(Item->title[9],"barkskin");}
  else if(roll<15){strcpy(Item->title[9],"bear's endurance");}
  else if(roll<16){strcpy(Item->title[9],"bull's strength");}
  else if(roll<18){strcpy(Item->title[9],"calm emotions");}
  else if(roll<19){strcpy(Item->title[9],"cat's grace");}
  else if(roll<22){strcpy(Item->title[9],"chill metal");}
  else if(roll<27){strcpy(Item->title[9],"cure moderate wounds");}
  else if(roll<29){strcpy(Item->title[9],"darkness");}
  else if(roll<31){strcpy(Item->title[9],"death knell");}
  else if(roll<34){strcpy(Item->title[9],"delay poison");}
  else if(roll<36){strcpy(Item->title[9],"eagle's splendor");}
  else if(roll<38){strcpy(Item->title[9],"enthrall");}
  else if(roll<41){strcpy(Item->title[9],"find traps");}
  else if(roll<43){strcpy(Item->title[9],"flame blade");}
  else if(roll<45){strcpy(Item->title[9],"flaming sphere");}
  else if(roll<47){strcpy(Item->title[9],"fog cloud");}
  else if(roll<48){strcpy(Item->title[9],"gentle repose");}
  else if(roll<50){strcpy(Item->title[9],"gust of wind");}
  else if(roll<51){strcpy(Item->title[9],"heat meta");}
  else if(roll<53){strcpy(Item->title[9],"hold animal");}
  else if(roll<55){strcpy(Item->title[9],"hold person");}
  else if(roll<58){strcpy(Item->title[9],"inflict moderate wounds");}
  else if(roll<59){strcpy(Item->title[9],"make whole");}
  else if(roll<61){strcpy(Item->title[9],"owl's wisdom");}
  else if(roll<62){strcpy(Item->title[9],"reduce anima");}
  else if(roll<64){strcpy(Item->title[9],"remove paralysis");}
  else if(roll<66){strcpy(Item->title[9],"resist energy");}
  else if(roll<69){strcpy(Item->title[9],"restoration, lesser");}
  else if(roll<70){strcpy(Item->title[9],"shatter");}
  else if(roll<72){strcpy(Item->title[9],"shield other");}
  else if(roll<75){strcpy(Item->title[9],"silence");}
  else if(roll<76){strcpy(Item->title[9],"soften earth and stone");}
  else if(roll<77){strcpy(Item->title[9],"sound burst");}
  else if(roll<78){strcpy(Item->title[9],"spider climb");}
  else if(roll<80){strcpy(Item->title[9],"spiritual weapon");}
  else if(roll<81){strcpy(Item->title[9],"status");}
  else if(roll<83){strcpy(Item->title[9],"summon monster II");}
  else if(roll<85){strcpy(Item->title[9],"summon nature's ally II");}
  else if(roll<87){strcpy(Item->title[9],"summon swarm");}
  else if(roll<88){strcpy(Item->title[9],"tree shape");}
  else if(roll<89){strcpy(Item->title[9],"undetectable alignment");}
  else if(roll<90){strcpy(Item->title[9],"warp wood");}
  else if(roll<91){strcpy(Item->title[9],"wood shape");}
  else if(roll<94){strcpy(Item->title[9],"zone of truth");}
  else if(roll<95){strcpy(Item->title[9],"augury");}
  else if(roll<97){strcpy(Item->title[9],"consecrate");}
  else if(roll<99){strcpy(Item->title[9],"desecrate");}
  else if(roll>=99){strcpy(Item->title[9],"fire trap");}
  return;
}
void Table5_40(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"bestow curse");}
  else if(roll<5){strcpy(Item->title[9],"blindness/deafness");}
  else if(roll<7){strcpy(Item->title[9],"call lightning");}
  else if(roll<9){strcpy(Item->title[9],"contagion");}
  else if(roll<11){strcpy(Item->title[9],"create food and water");}
  else if(roll<15){strcpy(Item->title[9],"cure serious wounds");}
  else if(roll<17){strcpy(Item->title[9],"daylight");}
  else if(roll<19){strcpy(Item->title[9],"deeper darkness");}
  else if(roll<20){strcpy(Item->title[9],"diminish plants");}
  else if(roll<24){strcpy(Item->title[9],"dispel magic");}
  else if(roll<25){strcpy(Item->title[9],"dominate animal");}
  else if(roll<26){strcpy(Item->title[9],"helping hand");}
  else if(roll<29){strcpy(Item->title[9],"inflict serious wounds");}
  else if(roll<32){strcpy(Item->title[9],"invisibility purge");}
  else if(roll<34){strcpy(Item->title[9],"locate object");}
  else if(roll<36){strcpy(Item->title[9],"magic circle against chaos");}
  else if(roll<38){strcpy(Item->title[9],"magic circle against evil");}
  else if(roll<40){strcpy(Item->title[9],"magic circle against law");}
  else if(roll<42){strcpy(Item->title[9],"magic fang, greater");}
  else if(roll<45){strcpy(Item->title[9],"magic vestment");}
  else if(roll<46){strcpy(Item->title[9],"meld into stone");}
  else if(roll<48){strcpy(Item->title[9],"obscure object");}
  else if(roll<50){strcpy(Item->title[9],"plant growth");}
  else if(roll<52){strcpy(Item->title[9],"poison");}
  else if(roll<55){strcpy(Item->title[9],"prayer");}
  else if(roll<59){strcpy(Item->title[9],"protection from energy");}
  else if(roll<60){strcpy(Item->title[9],"quench");}
  else if(roll<63){strcpy(Item->title[9],"remove blindness/deafness");}
  else if(roll<66){strcpy(Item->title[9],"remove curse");}
  else if(roll<69){strcpy(Item->title[9],"remove disease");}
  else if(roll<71){strcpy(Item->title[9],"searing light");}
  else if(roll<73){strcpy(Item->title[9],"sleet storm");}
  else if(roll<75){strcpy(Item->title[9],"snare");}
  else if(roll<78){strcpy(Item->title[9],"speak with dead");}
  else if(roll<80){strcpy(Item->title[9],"speak with plants");}
  else if(roll<82){strcpy(Item->title[9],"spike growth");}
  else if(roll<84){strcpy(Item->title[9],"stone shape");}
  else if(roll<86){strcpy(Item->title[9],"summon monster III");}
  else if(roll<88){strcpy(Item->title[9],"summon nature's ally III");}
  else if(roll<90){strcpy(Item->title[9],"water breathing");}
  else if(roll<92){strcpy(Item->title[9],"water walk");}
  else if(roll<94){strcpy(Item->title[9],"wind wall");}
  else if(roll<96){strcpy(Item->title[9],"continual flame");}
  else if(roll<98){strcpy(Item->title[9],"glyph of warding");}
  else if(roll>=98){strcpy(Item->title[9],"animate dead");}
  return;
}
void Table5_41(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"air walk");}
  else if(roll<5){strcpy(Item->title[9],"antiplant shell");}
  else if(roll<7){strcpy(Item->title[9],"blight");}
  else if(roll<9){strcpy(Item->title[9],"chaos hammer");}
  else if(roll<11){strcpy(Item->title[9],"command plants");}
  else if(roll<13){strcpy(Item->title[9],"control water");}
  else if(roll<17){strcpy(Item->title[9],"cure critical wounds");}
  else if(roll<20){strcpy(Item->title[9],"death ward");}
  else if(roll<24){strcpy(Item->title[9],"dimensional anchor");}
  else if(roll<27){strcpy(Item->title[9],"discern lies");}
  else if(roll<31){strcpy(Item->title[9],"dismissal");}
  else if(roll<34){strcpy(Item->title[9],"divine power");}
  else if(roll<38){strcpy(Item->title[9],"flame strike");}
  else if(roll<41){strcpy(Item->title[9],"freedom of movement");}
  else if(roll<43){strcpy(Item->title[9],"giant vermin");}
  else if(roll<46){strcpy(Item->title[9],"holy smite");}
  else if(roll<48){strcpy(Item->title[9],"ice storm");}
  else if(roll<50){strcpy(Item->title[9],"imbue with spell ability");}
  else if(roll<53){strcpy(Item->title[9],"inflict critical wounds");}
  else if(roll<57){strcpy(Item->title[9],"magic weapon, greater");}
  else if(roll<59){strcpy(Item->title[9],"neutralize poison");}
  else if(roll<61){strcpy(Item->title[9],"order's wrath");}
  else if(roll<63){strcpy(Item->title[9],"poison");}
  else if(roll<66){strcpy(Item->title[9],"reincarnate");}
  else if(roll<68){strcpy(Item->title[9],"repel vermin");}
  else if(roll<70){strcpy(Item->title[9],"rusting grasp");}
  else if(roll<72){strcpy(Item->title[9],"scrying");}
  else if(roll<74){strcpy(Item->title[9],"sending");}
  else if(roll<78){strcpy(Item->title[9],"spell immunity");}
  else if(roll<80){strcpy(Item->title[9],"spike stones");}
  else if(roll<83){strcpy(Item->title[9],"summon monster IV");}
  else if(roll<86){strcpy(Item->title[9],"summon nature's ally IV");}
  else if(roll<89){strcpy(Item->title[9],"tongues");}
  else if(roll<91){strcpy(Item->title[9],"unholy blight");}
  else if(roll<93){strcpy(Item->title[9],"divination");}
  else if(roll<97){strcpy(Item->title[9],"planar ally, lesser");}
  else if(roll>=97){strcpy(Item->title[9],"restoration");}
  return;
}
void Table5_42(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"animal growth");}
  else if(roll<5){strcpy(Item->title[9],"atonement");}
  else if(roll<8){strcpy(Item->title[9],"baleful polymorph");}
  else if(roll<12){strcpy(Item->title[9],"break enchantment");}
  else if(roll<16){strcpy(Item->title[9],"breath of life");}
  else if(roll<18){strcpy(Item->title[9],"call lightning storm");}
  else if(roll<20){strcpy(Item->title[9],"command, greater");}
  else if(roll<22){strcpy(Item->title[9],"commune with nature");}
  else if(roll<24){strcpy(Item->title[9],"control winds");}
  else if(roll<27){strcpy(Item->title[9],"cure light wounds, mass");}
  else if(roll<29){strcpy(Item->title[9],"death ward");}
  else if(roll<30){strcpy(Item->title[9],"dispel chaos");}
  else if(roll<31){strcpy(Item->title[9],"dispel evil");}
  else if(roll<32){strcpy(Item->title[9],"dispel good");}
  else if(roll<33){strcpy(Item->title[9],"dispel law");}
  else if(roll<36){strcpy(Item->title[9],"disrupting weapon");}
  else if(roll<38){strcpy(Item->title[9],"inflict light wounds, mass");}
  else if(roll<40){strcpy(Item->title[9],"insect plague");}
  else if(roll<42){strcpy(Item->title[9],"mark of justice");}
  else if(roll<45){strcpy(Item->title[9],"plane shift");}
  else if(roll<48){strcpy(Item->title[9],"righteous might");}
  else if(roll<51){strcpy(Item->title[9],"scrying");}
  else if(roll<54){strcpy(Item->title[9],"slay living");}
  else if(roll<57){strcpy(Item->title[9],"spell resistance");}
  else if(roll<60){strcpy(Item->title[9],"summon monster V");}
  else if(roll<62){strcpy(Item->title[9],"summon nature's ally V");}
  else if(roll<63){strcpy(Item->title[9],"transmute mud to rock");}
  else if(roll<64){strcpy(Item->title[9],"transmute rock to mud");}
  else if(roll<66){strcpy(Item->title[9],"tree stride");}
  else if(roll<68){strcpy(Item->title[9],"wall of fire");}
  else if(roll<70){strcpy(Item->title[9],"wall of thorns");}
  else if(roll<72){strcpy(Item->title[9],"wall of stone");}
  else if(roll<74){strcpy(Item->title[9],"stoneskin");}
  else if(roll<78){strcpy(Item->title[9],"true seeing");}
  else if(roll<81){strcpy(Item->title[9],"commune");}
  else if(roll<83){strcpy(Item->title[9],"hallow");}
  else if(roll<86){strcpy(Item->title[9],"symbol of pain");}
  else if(roll<89){strcpy(Item->title[9],"symbol of sleep");}
  else if(roll<91){strcpy(Item->title[9],"unhallow");}
  else if(roll<93){strcpy(Item->title[9],"awaken");}
  else if(roll<95){strcpy(Item->title[9],"hallow");}
  else if(roll<99){strcpy(Item->title[9],"raise dead");}
  else if(roll>=99){strcpy(Item->title[9],"unhallow");}
  return;
}
void Table5_43(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"animate objects");}
  else if(roll<5){strcpy(Item->title[9],"antilife shell");}
  else if(roll<7){strcpy(Item->title[9],"banishment");}
  else if(roll<9){strcpy(Item->title[9],"bear's endurance, mass");}
  else if(roll<11){strcpy(Item->title[9],"blade barrier");}
  else if(roll<13){strcpy(Item->title[9],"bull's strength, mass");}
  else if(roll<15){strcpy(Item->title[9],"cat's grace, mass");}
  else if(roll<19){strcpy(Item->title[9],"cure moderate wounds, mass");}
  else if(roll<23){strcpy(Item->title[9],"dispel magic, greater");}
  else if(roll<26){strcpy(Item->title[9],"eagle's splendor, mass");}
  else if(roll<30){strcpy(Item->title[9],"find the path");}
  else if(roll<32){strcpy(Item->title[9],"fire seeds");}
  else if(roll<34){strcpy(Item->title[9],"geas/quest");}
  else if(roll<38){strcpy(Item->title[9],"harm");}
  else if(roll<43){strcpy(Item->title[9],"heal");}
  else if(roll<46){strcpy(Item->title[9],"heroes' feast");}
  else if(roll<49){strcpy(Item->title[9],"inflict moderate wounds, mass");}
  else if(roll<52){strcpy(Item->title[9],"ironwood");}
  else if(roll<55){strcpy(Item->title[9],"liveoak");}
  else if(roll<57){strcpy(Item->title[9],"move earth");}
  else if(roll<60){strcpy(Item->title[9],"owl's wisdom, mass");}
  else if(roll<62){strcpy(Item->title[9],"repel wood");}
  else if(roll<65){strcpy(Item->title[9],"spellstaff");}
  else if(roll<67){strcpy(Item->title[9],"stone tell");}
  else if(roll<70){strcpy(Item->title[9],"summon monster VI");}
  else if(roll<72){strcpy(Item->title[9],"summon nature's ally VI");}
  else if(roll<74){strcpy(Item->title[9],"transport via plants");}
  else if(roll<76){strcpy(Item->title[9],"wind walk");}
  else if(roll<78){strcpy(Item->title[9],"word of recall");}
  else if(roll<81){strcpy(Item->title[9],"create undead");}
  else if(roll<84){strcpy(Item->title[9],"glyph of warding, greater");}
  else if(roll<88){strcpy(Item->title[9],"undeath to death");}
  else if(roll<91){strcpy(Item->title[9],"symbol of fear");}
  else if(roll<95){strcpy(Item->title[9],"planar ally");}
  else if(roll<98){strcpy(Item->title[9],"forbiddance (in 60ft cube)");}
  else if(roll>=98){strcpy(Item->title[9],"symbol of persuasion");}
  return;
}
void Table5_44(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"animate plants");}
  else if(roll<8){strcpy(Item->title[9],"blasphemy");}
  else if(roll<10){strcpy(Item->title[9],"changestaff");}
  else if(roll<13){strcpy(Item->title[9],"control weather");}
  else if(roll<16){strcpy(Item->title[9],"creeping doom");}
  else if(roll<21){strcpy(Item->title[9],"cure serious wounds, mass");}
  else if(roll<25){strcpy(Item->title[9],"dictum");}
  else if(roll<30){strcpy(Item->title[9],"ethereal jaunt");}
  else if(roll<34){strcpy(Item->title[9],"fire storm");}
  else if(roll<39){strcpy(Item->title[9],"holy word");}
  else if(roll<42){strcpy(Item->title[9],"inflict serious wounds, mass");}
  else if(roll<47){strcpy(Item->title[9],"regenerate");}
  else if(roll<51){strcpy(Item->title[9],"repulsion");}
  else if(roll<55){strcpy(Item->title[9],"scrying, greater");}
  else if(roll<59){strcpy(Item->title[9],"summon monster VII");}
  else if(roll<62){strcpy(Item->title[9],"summon nature's ally VII");}
  else if(roll<66){strcpy(Item->title[9],"sunbeam");}
  else if(roll<68){strcpy(Item->title[9],"transmute metal to wood");}
  else if(roll<72){strcpy(Item->title[9],"word of chaos");}
  else if(roll<76){strcpy(Item->title[9],"destruction");}
  else if(roll<78){strcpy(Item->title[9],"refuge");}
  else if(roll<86){strcpy(Item->title[9],"restoration, greater");}
  else if(roll<89){strcpy(Item->title[9],"symbol of stunning");}
  else if(roll<92){strcpy(Item->title[9],"symbol of weakness");}
  else if(roll>=92){strcpy(Item->title[9],"resurrection");}
  return;
}
void Table5_45(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<4){strcpy(Item->title[9],"animal shapes");}
  else if(roll<10){strcpy(Item->title[9],"antimagic field");}
  else if(roll<15){strcpy(Item->title[9],"cloak of chaos");}
  else if(roll<18){strcpy(Item->title[9],"control plants");}
  else if(roll<23){strcpy(Item->title[9],"cure critical wounds, mass");}
  else if(roll<29){strcpy(Item->title[9],"dimensional lock");}
  else if(roll<31){strcpy(Item->title[9],"discern location");}
  else if(roll<35){strcpy(Item->title[9],"earthquake");}
  else if(roll<38){strcpy(Item->title[9],"finger of death");}
  else if(roll<43){strcpy(Item->title[9],"holy aura");}
  else if(roll<46){strcpy(Item->title[9],"inflict critical wounds, mass");}
  else if(roll<49){strcpy(Item->title[9],"repel metal or stone");}
  else if(roll<52){strcpy(Item->title[9],"reverse gravity");}
  else if(roll<54){strcpy(Item->title[9],"shield of law");}
  else if(roll<59){strcpy(Item->title[9],"spell immunity, greater");}
  else if(roll<42){strcpy(Item->title[9],"summon monster VIII");}
  else if(roll<65){strcpy(Item->title[9],"summon nature's ally VIII");}
  else if(roll<71){strcpy(Item->title[9],"sunburst");}
  else if(roll<76){strcpy(Item->title[9],"unholy aura");}
  else if(roll<79){strcpy(Item->title[9],"whirlwind");}
  else if(roll<86){strcpy(Item->title[9],"create greater undead");}
  else if(roll<93){strcpy(Item->title[9],"planar ally, greater");}
  else if(roll<97){strcpy(Item->title[9],"symbol of death");}
  else if(roll>=97){strcpy(Item->title[9],"symbol of insanity");}
  return;
}
void Table5_46(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<4){strcpy(Item->title[9],"antipathy");}
  else if(roll<10){strcpy(Item->title[9],"elemental swarm");}
  else if(roll<15){strcpy(Item->title[9],"energy drain");}
  else if(roll<23){strcpy(Item->title[9],"etherealness");}
  else if(roll<26){strcpy(Item->title[9],"foresight");}
  else if(roll<36){strcpy(Item->title[9],"gate");}
  else if(roll<40){strcpy(Item->title[9],"heal, mass");}
  else if(roll<45){strcpy(Item->title[9],"implosion");}
  else if(roll<53){strcpy(Item->title[9],"miracle");}
  else if(roll<58){strcpy(Item->title[9],"shambler");}
  else if(roll<68){strcpy(Item->title[9],"shapechange");}
  else if(roll<71){strcpy(Item->title[9],"soul bind");}
  else if(roll<75){strcpy(Item->title[9],"storm of vengeance");}
  else if(roll<81){strcpy(Item->title[9],"summon monster IX");}
  else if(roll<88){strcpy(Item->title[9],"summon nature's ally IX");}
  else if(roll<91){strcpy(Item->title[9],"astral projection");}
  else if(roll<94){strcpy(Item->title[9],"sympathy");}
  else if(roll>=94){strcpy(Item->title[9],"true resurrection");}
  return;
}
void Table5_20(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<15){strcpy(Item->title[9],"arcane mark");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<29){strcpy(Item->title[9],"guidance");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<45){strcpy(Item->title[9],"light");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<59){strcpy(Item->title[9],"purify food and drink");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<73){strcpy(Item->title[9],"resistance");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<87){strcpy(Item->title[9],"stabilize");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll>=87){strcpy(Item->title[9],"virtue");strcpy(Item->title[8],"Potion or oil of");}
  return ;
}
void Table5_21(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"animate rope");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<7){strcpy(Item->title[9],"bless weapon");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<17){strcpy(Item->title[9],"cure light wounds");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<21){strcpy(Item->title[9],"endure elements");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<27){strcpy(Item->title[9],"enlarge person");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<30){strcpy(Item->title[9],"erase");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<33){strcpy(Item->title[9],"goodberry");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<35){strcpy(Item->title[9],"grease");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<39){strcpy(Item->title[9],"hide from animals");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<43){strcpy(Item->title[9],"hide from undead");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<45){strcpy(Item->title[9],"hold portal");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<49){strcpy(Item->title[9],"jump");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<53){strcpy(Item->title[9],"mage armor");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<57){strcpy(Item->title[9],"magic fang");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<61){strcpy(Item->title[9],"magic stone");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<65){strcpy(Item->title[9],"magic weapon");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<69){strcpy(Item->title[9],"pass without trace");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<72){strcpy(Item->title[9],"protection from chaos");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<75){strcpy(Item->title[9],"protection from evil");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<78){strcpy(Item->title[9],"protection from good");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<81){strcpy(Item->title[9],"protection from law");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<85){strcpy(Item->title[9],"reduce person");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<89){strcpy(Item->title[9],"remove fear");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<93){strcpy(Item->title[9],"sanctuary");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<97){strcpy(Item->title[9],"shield of faith");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll>=97){strcpy(Item->title[9],"shillelagh");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<97){strcpy(Item->title[9],"");strcpy(Item->title[8],"Potion or oil of");}
  return ;
}
void Table5_22(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"aid");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<5){strcpy(Item->title[9],"align weapon");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<7){strcpy(Item->title[9],"arcane lock");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<11){strcpy(Item->title[9],"barkskin");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<16){strcpy(Item->title[9],"bear's endurance");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<18){strcpy(Item->title[9],"blur");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<23){strcpy(Item->title[9],"bull's strength");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<27){strcpy(Item->title[9],"cat's grace");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<37){strcpy(Item->title[9],"cure moderate wounds");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<38){strcpy(Item->title[9],"darkness");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<41){strcpy(Item->title[9],"darkvision");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<44){strcpy(Item->title[9],"delay poison");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<47){strcpy(Item->title[9],"eagle's splendor");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<50){strcpy(Item->title[9],"fox's cunning");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<52){strcpy(Item->title[9],"gentle repose");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<58){strcpy(Item->title[9],"invisibility");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<62){strcpy(Item->title[9],"levitate");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<63){strcpy(Item->title[9],"make whole");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<65){strcpy(Item->title[9],"obscure object");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<68){strcpy(Item->title[9],"owl's wisdom");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<70){strcpy(Item->title[9],"protection from arrows");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<71){strcpy(Item->title[9],"reduce animal");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<74){strcpy(Item->title[9],"remove paralysis");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<75){strcpy(Item->title[9],"resist energy, acid");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<76){strcpy(Item->title[9],"resist energy, cold");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<77){strcpy(Item->title[9],"resist energy, electricity");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<78){strcpy(Item->title[9],"resist energy, fire");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<79){strcpy(Item->title[9],"resist energy, sonic");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<84){strcpy(Item->title[9],"rope trick");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<87){strcpy(Item->title[9],"shatter");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<91){strcpy(Item->title[9],"spider climb");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<93){strcpy(Item->title[9],"status");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<95){strcpy(Item->title[9],"undetectable alignment");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<97){strcpy(Item->title[9],"warp wood");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<99){strcpy(Item->title[9],"wood shape");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll>=99){strcpy(Item->title[9],"continual flame");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<97){strcpy(Item->title[9],"");strcpy(Item->title[8],"Potion or oil of");}
  return ;
}
void Table5_23(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<11){strcpy(Item->title[9],"cure serious wounds");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<13){strcpy(Item->title[9],"daylight");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<15){strcpy(Item->title[9],"dispel magic");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<19){strcpy(Item->title[9],"displacement");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<21){strcpy(Item->title[9],"fire trap");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<23){strcpy(Item->title[9],"flame arrow");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<29){strcpy(Item->title[9],"fly");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<35){strcpy(Item->title[9],"gaseous form");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<37){strcpy(Item->title[9],"good hope");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<43){strcpy(Item->title[9],"haste");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<49){strcpy(Item->title[9],"heroism");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<53){strcpy(Item->title[9],"keen edge");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<57){strcpy(Item->title[9],"magic fang, greater");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<60){strcpy(Item->title[9],"magic vestment");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<63){strcpy(Item->title[9],"neutralize poison");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<64){strcpy(Item->title[9],"protection from energy, acid");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<65){strcpy(Item->title[9],"protection from energy, cold");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<66){strcpy(Item->title[9],"protection from energy, electricity");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<67){strcpy(Item->title[9],"protection from energy, fire");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<68){strcpy(Item->title[9],"protection from energy, sonic");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<72){strcpy(Item->title[9],"rage");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<76){strcpy(Item->title[9],"remove blindness/deafness");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<80){strcpy(Item->title[9],"remove curse");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<84){strcpy(Item->title[9],"remove disease");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<86){strcpy(Item->title[9],"shrink item");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<88){strcpy(Item->title[9],"stone shape");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<92){strcpy(Item->title[9],"tongues");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<96){strcpy(Item->title[9],"water breathing");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll<99){strcpy(Item->title[9],"water walk");strcpy(Item->title[8],"Potion or oil of");}
  else if(roll>=99){strcpy(Item->title[9],"nondetection");strcpy(Item->title[8],"Potion or oil of");}
  //else if(roll<97){strcpy(Item->title[9],"");strcpy(Item->title[8],"Potion or oil of");}
  return ;}
void Table5_19(Item_st *Item, int Tier){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(Tier==1){
    if(roll<21){Table5_20(Item);}
    else if(roll<61){Table5_21(Item);}
    else if(roll>=61){Table5_22(Item);}
  }
  else if(Tier==2){
    if(roll<21){Table5_21(Item);}
    else if(roll<61){Table5_22(Item);}
    else if(roll>=61){Table5_23(Item);}
  }
  else if(Tier==3){
    if(roll<21){Table5_22(Item);}
    else if(roll>=21){Table5_23(Item);}
  }
  return ;
}
void Table5_15(Item_st *Item,int BaseMat){
  int Adjective=FindSpot(Item);
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(BaseMat==0){
    if(roll<91){return;}
    else if(roll<93){strcpy(Item->title[Adjective],"Adamantine");}
    else if(roll<96){strcpy(Item->title[Adjective],"Cold Iron");}
    else if(roll<97){strcpy(Item->title[Adjective],"Mithral");}
    else if(roll>=97){strcpy(Item->title[Adjective],"Silver");}
  }
  else if(BaseMat==1){
    if(roll<91){return;}
    else if(roll<93){strcpy(Item->title[Adjective],"Adamantine1");}
    else if(roll<95){strcpy(Item->title[Adjective],"Cold Iron");}
    else if(roll<97){strcpy(Item->title[Adjective],"Darkwood");}
    else if(roll<99){strcpy(Item->title[Adjective],"Mithral");}
    else if(roll>=99){strcpy(Item->title[Adjective],"Silver");}
  }
  else if(BaseMat==2){
    if(roll<91){return;}
    else if(roll>=91){strcpy(Item->title[Adjective],"Darkwood");}
  }
  return;
}
void Table5_12(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<6){strcpy(Item->title[9],"Blowgun");}
  else if(roll<9){strcpy(Item->title[9],"Darts, blowgun (10");}
  else if(roll<14){strcpy(Item->title[9],"Club");Table5_6(Item, METALS);}
  else if(roll<17){strcpy(Item->title[9],"Crossbow, heavy");Table5_6(Item, METALS);}
  else if(roll<22){strcpy(Item->title[9],"Crossbow, light");Table5_6(Item, DRAGONHIDE);}
  else if(roll<25){strcpy(Item->title[9],"Bolts, crossbow (10)");Table5_6(Item, METALS);}
  else if(roll<30){strcpy(Item->title[9],"Dagger");Table5_6(Item, METALS);}
  else if(roll<35){strcpy(Item->title[9],"Dagger, punching");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<40){strcpy(Item->title[9],"Dart");Table5_6(Item, METALS);}
  else if(roll<45){strcpy(Item->title[9],"Gauntlet");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<50){strcpy(Item->title[9],"Gauntlet, spiked");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<55){strcpy(Item->title[9],"Javelin");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<60){strcpy(Item->title[9],"Longspear");Table5_3(Item);}
  else if(roll<63){strcpy(Item->title[9],"Mace, heavy");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<68){strcpy(Item->title[9],"Mace, light");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<73){strcpy(Item->title[9],"Morningstar");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<78){strcpy(Item->title[9],"Quarterstaff");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<83){strcpy(Item->title[9],"Shortspear");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<88){strcpy(Item->title[9],"Sickle");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<93){strcpy(Item->title[9],"Sling");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll<96){strcpy(Item->title[9],"Bullets, sling (10)");Table5_6(Item, DRAGONHIDEANDMETALS);}
  else if(roll>=96){strcpy(Item->title[9],"Spear");Table5_3(Item);}
  return ;
}
void Table5_13(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<3){strcpy(Item->title[9],"Axe, throwing");Table5_15(Item, METALS);}
  else if(roll<5){strcpy(Item->title[9],"Battleaxe");Table5_15(Item, METALS);}
  else if(roll<7){strcpy(Item->title[9],"Falchion");Table5_15(Item, METALS);}
  else if(roll<10){strcpy(Item->title[9],"Flail");Table5_15(Item, METALS);}
  else if(roll<12){strcpy(Item->title[9],"Flail, heavy");Table5_15(Item, METALS);}
  else if(roll<14){strcpy(Item->title[9],"Glaive");Table5_15(Item, METALS);}
  else if(roll<17){strcpy(Item->title[9],"Greataxe");Table5_15(Item, METALS);}
  else if(roll<20){strcpy(Item->title[9],"Greatclub");Table5_15(Item, METALS);}
  else if(roll<23){strcpy(Item->title[9],"Greatsword");Table5_15(Item, METALS);}
  else if(roll<25){strcpy(Item->title[9],"Guisarme");Table5_15(Item, METALS);}
  else if(roll<27){strcpy(Item->title[9],"Halberd");Table5_15(Item, METALS);}
  else if(roll<30){strcpy(Item->title[9],"Hammer, light");Table5_15(Item, METALS);}
  else if(roll<33){strcpy(Item->title[9],"Handaxe");Table5_15(Item, METALS);}
  else if(roll<35){strcpy(Item->title[9],"Kukri");Table5_15(Item, METALS);}
  else if(roll<38){strcpy(Item->title[9],"Lance");Table5_15(Item, METALS);}
  else if(roll<42){strcpy(Item->title[9],"Longbow");Table5_15(Item, METALS);}
  else if(roll<46){strcpy(Item->title[9],"Longbow, composite");Table5_15(Item, METALS);}
  else if(roll<49){strcpy(Item->title[9],"Arrows (20)");Table5_15(Item, METALS);}
  else if(roll<52){strcpy(Item->title[9],"Longsword");Table5_15(Item, METALS);}
  else if(roll<54){strcpy(Item->title[9],"Pick, heavy");Table5_15(Item, METALS);}
  else if(roll<57){strcpy(Item->title[9],"Pick, light");Table5_15(Item, METALS);}
  else if(roll<59){strcpy(Item->title[9],"Ranseur");Table5_15(Item, METALS);}
  else if(roll<62){strcpy(Item->title[9],"Rapier");}
  else if(roll<64){strcpy(Item->title[9],"Sap");Table5_15(Item, METALS);}
  else if(roll<67){strcpy(Item->title[9],"Scimitar");Table5_15(Item, METALS);}
  else if(roll<70){strcpy(Item->title[9],"Scythe");Table5_15(Item, METALS);}
  else if(roll<79){strcpy(Item->title[9],"Shortbow");Table5_15(Item, METALS);}
  else if(roll<83){strcpy(Item->title[9],"Shortbow, composite");Table5_15(Item, METALS);}
  //else if(roll<84){strcpy(Item->title[Adjective],"Armor spikes");/*TO DO*/}
  //else if(roll<90){strcpy(Item->title[Adjective],"Shield spikes");/*TO DO*/}
  else if(roll<92){strcpy(Item->title[9],"Starknife");Table5_15(Item, METALS);}
  else if(roll<95){strcpy(Item->title[9],"Sword, short");Table5_15(Item, METALS);}
  else if(roll<98){strcpy(Item->title[9],"Trident");Table5_15(Item, WOODANDMETALS);}
  else if(roll>=98){strcpy(Item->title[9],"Warhammer");Table5_15(Item, METALS);}

  return ;
}
void Table5_14(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<6){strcpy(Item->title[9],"Axe, orc double");Table5_15(Item, METALS);}
  else if(roll<11){strcpy(Item->title[9],"Bolas");}
  else if(roll<16){strcpy(Item->title[9],"Chain, spiked");Table5_15(Item, METALS);}
  else if(roll<21){strcpy(Item->title[9],"Crossbow, hand");}
  else if(roll<24){strcpy(Item->title[9],"Bolts, hand crossbow (10");Table5_15(Item, METALS);}
  else if(roll<27){strcpy(Item->title[9],"Crossbow, repeating heavy");}
  else if(roll<30){strcpy(Item->title[9],"Crossbow, repeating light");}
  else if(roll<33){strcpy(Item->title[9],"Bolts, repeating crossbow (5)");Table5_15(Item, METALS);}
  else if(roll<38){strcpy(Item->title[9],"Curve blade, elven");Table5_15(Item, METALS);}
  else if(roll<43){strcpy(Item->title[9],"Flail, dire");Table5_15(Item, METALS);}
  else if(roll<48){strcpy(Item->title[9],"Hammer, gnome hooked");Table5_15(Item, METALS);}
  else if(roll<53){strcpy(Item->title[9],"Kama");Table5_15(Item, METALS);}
  else if(roll<56){strcpy(Item->title[9],"Net");}
  else if(roll<61){strcpy(Item->title[9],"Nunchaku");Table5_15(Item, WOOD);}
  else if(roll<66){strcpy(Item->title[9],"Sai");Table5_15(Item, METALS);}
  else if(roll<71){strcpy(Item->title[9],"Shuriken (5) ");Table5_15(Item, METALS);}
  else if(roll<75){strcpy(Item->title[9],"Siangham");Table5_15(Item, METALS);}
  else if(roll<80){strcpy(Item->title[9],"Sling staff, halfling");Table5_15(Item, WOOD);}
  else if(roll<83){strcpy(Item->title[9],"Bullets, sling (10)");Table5_15(Item, METALS);}
  else if(roll<87){strcpy(Item->title[9],"Sword, bastard");Table5_15(Item, METALS);}
  else if(roll<91){strcpy(Item->title[9],"Sword, two-bladed");Table5_15(Item, METALS);}
  else if(roll<94){strcpy(Item->title[9],"Urgrosh, dwarven");Table5_15(Item, METALS);}
  else if(roll<97){strcpy(Item->title[9],"Waraxe, dwarven");Table5_15(Item, METALS);}
  else if(roll>=97){strcpy(Item->title[9],"Whip");}
  return ;
}
void Table5_11(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<46){Table5_12(Item);}
  else if(roll<81){Table5_13(Item);}
  else if(roll>=81){Table5_14(Item);}
  return ;
}
void Table5_26(Item_st *Item, int Tier, int MagicType){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if (MagicType==ARCANE) {
  if(Tier==1){
    if(roll<6){Table5_27(Item);}
    else if(roll<51){Table5_28(Item);}
    else if(roll<96){Table5_29(Item);}
    else if(roll>=96){Table5_30(Item);}
  }
  if(Tier==2){
    if(roll<6){Table5_29(Item);}
    else if(roll<66){Table5_30(Item);}
    else if(roll<96){Table5_31(Item);}
    else if(roll>=96){Table5_32(Item);}
  }
  if(Tier==3){
    if(roll<6){Table5_31(Item);}
    else if(roll<51){Table5_32(Item);}
    else if(roll<71){Table5_33(Item);}
    else if(roll<86){Table5_34(Item);}
    else if(roll<96){Table5_35(Item);}
    else if(roll>=96){Table5_36(Item);}
  }
  }
  if (MagicType==DIVINE) {
  if(Tier==1){
      if(roll<6){Table5_37(Item);}
      else if(roll<51){Table5_38(Item);}
      else if(roll<96){Table5_39(Item);}
      else if(roll>=96){Table5_40(Item);}
    }
  if(Tier==2){
      if(roll<6){Table5_39(Item);}
      else if(roll<66){Table5_40(Item);}
      else if(roll<96){Table5_41(Item);}
      else if(roll>=96){Table5_42(Item);}
    }
  if(Tier==3){
      if(roll<6){Table5_41(Item);}
      else if(roll<51){Table5_42(Item);}
      else if(roll<71){Table5_43(Item);}
      else if(roll<86){Table5_44(Item);}
      else if(roll<96){Table5_45(Item);}
      else if(roll>=96){Table5_46(Item);}
    }
  }
  return;
}
void Table5_25(Item_st *Item, int Tier, int MagicType){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<81){strcpy(Item->title[8],"One scroll of");Table5_26(Item, Tier, MagicType);}
  else if(roll<96){strcpy(Item->title[8],"Two scrolls of");Table5_26(Item, Tier, MagicType);}
  else if(roll>=96){strcpy(Item->title[8],"Three scrolls of");Table5_26(Item, Tier, MagicType);}
  return;
}
void Table5_24(Item_st *Item, int Tier){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<71){Table5_25(Item, Tier, ARCANE);}//arcane
  else if(roll>=71){Table5_25(Item, Tier, DIVINE);}//divine
  return;
}
void Table15_18(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<2){strcpy(Item->title[9],"Feather token, anchor");}
  else if(roll<3){strcpy(Item->title[9],"Universal solvent");}
  else if(roll<4){strcpy(Item->title[9],"Elixir of love");}
  else if(roll<5){strcpy(Item->title[9],"Unguent of timelessness");}
  else if(roll<6){strcpy(Item->title[9],"Feather token, fan");}
  else if(roll<7){strcpy(Item->title[9],"Dust of tracelessness");}
  else if(roll<8){strcpy(Item->title[9],"Elixir of hiding");}
  else if(roll<9){strcpy(Item->title[9],"Elixir of tumbling");}
  else if(roll<10){strcpy(Item->title[9],"Elixir of swimming");}
  else if(roll<11){strcpy(Item->title[9],"Elixir of vision");}
  else if(roll<12){strcpy(Item->title[9],"Silversheen");}
  else if(roll<13){strcpy(Item->title[9],"Feather token, bird");}
  else if(roll<14){strcpy(Item->title[9],"Feather token, tree");}
  else if(roll<15){strcpy(Item->title[9],"Feather token, swan boat");}
  else if(roll<16){strcpy(Item->title[9],"Elixir of truth");}
  else if(roll<17){strcpy(Item->title[9],"Feather token, whip");}
  else if(roll<18){strcpy(Item->title[9],"Dust of dryness");}
  else if(roll<19){strcpy(Item->title[9],"Hand of the mage");}
  else if(roll<20){strcpy(Item->title[9],"Bracers of armor +1");}
  else if(roll<21){strcpy(Item->title[9],"Cloak of resistance +1");}
  else if(roll<22){strcpy(Item->title[9],"Pearl of power, 1st-level spell");}
  else if(roll<23){strcpy(Item->title[9],"Phylactery of faithfulness");}
  else if(roll<24){strcpy(Item->title[9],"Salve of slipperiness");}
  else if(roll<25){strcpy(Item->title[9],"Elixir of fire breath");}
  else if(roll<26){strcpy(Item->title[9],"Pipes of the sewers");}
  else if(roll<27){strcpy(Item->title[9],"Dust of illusion");}
  else if(roll<28){strcpy(Item->title[9],"Brooch of shielding");}
  else if(roll<29){strcpy(Item->title[9],"Necklace of fireballs type I");}
  else if(roll<30){strcpy(Item->title[9],"Dust of appearance");}
  else if(roll<31){strcpy(Item->title[9],"Hat of disguise");}
  else if(roll<32){strcpy(Item->title[9],"Pipes of sounding");}
  else if(roll<33){strcpy(Item->title[9],"Efficient quiver");}
  else if(roll<34){strcpy(Item->title[9],"Amulet of natural armor +1");}
  else if(roll<35){strcpy(Item->title[9],"Handy haversack");}
  else if(roll<36){strcpy(Item->title[9],"Horn of fog");}
  else if(roll<37){strcpy(Item->title[9],"Elemental gem");}
  else if(roll<38){strcpy(Item->title[9],"Robe of bones");}
  else if(roll<39){strcpy(Item->title[9],"Sovereign glue");}
  else if(roll<40){strcpy(Item->title[9],"Bag of holding type I");}
  else if(roll<41){strcpy(Item->title[9],"Boots of elvenkind");}
  else if(roll<42){strcpy(Item->title[9],"Boots of the winterlands");}
  else if(roll<43){strcpy(Item->title[9],"Candle of truth");}
  else if(roll<44){strcpy(Item->title[9],"Cloak of elvenkind");}
  else if(roll<45){strcpy(Item->title[9],"Eyes of the eagle");}
  else if(roll<46){strcpy(Item->title[9],"Goggles of minute seeing");}
  else if(roll<47){strcpy(Item->title[9],"Scarab, golembane");}
  else if(roll<48){strcpy(Item->title[9],"Necklace of fireballs type II");}
  else if(roll<49){strcpy(Item->title[9],"Stone of alarm");}
  else if(roll<50){strcpy(Item->title[9],"Bead of force");}
  else if(roll<51){strcpy(Item->title[9],"Chime of opening");}
  else if(roll<52){strcpy(Item->title[9],"Horseshoes of speed");}
  else if(roll<53){strcpy(Item->title[9],"Rope of climbing");}
  else if(roll<54){strcpy(Item->title[9],"Bag of tricks, gray");}
  else if(roll<55){strcpy(Item->title[9],"Dust of disappearance");}
  else if(roll<56){strcpy(Item->title[9],"Lens of detection");}
  else if(roll<57){strcpy(Item->title[9],"Vestment, druid’s");}
  else if(roll<58){strcpy(Item->title[9],"Figurine of wondrous power, silver raven");}
  else if(roll<59){strcpy(Item->title[9],"Belt of giant strength +2");}
  else if(roll<60){strcpy(Item->title[9],"Belt of incredible dexterity +2");}
  else if(roll<61){strcpy(Item->title[9],"Belt of mighty constitution +2");}
  else if(roll<62){strcpy(Item->title[9],"Bracers of armor +2");}
  else if(roll<63){strcpy(Item->title[9],"Cloak of resistance +2");}
  else if(roll<64){strcpy(Item->title[9],"Gloves of arrow snaring");}
  else if(roll<65){strcpy(Item->title[9],"Headband of alluring charisma +2");}
  else if(roll<66){strcpy(Item->title[9],"Headband of inspired wisdom +2");}
  else if(roll<67){strcpy(Item->title[9],"Headband of vast intelligence +2");}
  else if(roll<68){strcpy(Item->title[9],"Ioun stone, clear spindle");}
  else if(roll<69){strcpy(Item->title[9],"Restorative ointment");}
  else if(roll<70){strcpy(Item->title[9],"Marvelous pigments");}
  else if(roll<71){strcpy(Item->title[9],"Pearl of power, 2nd-level spell");}
  else if(roll<72){strcpy(Item->title[9],"Stone salve");}
  else if(roll<73){strcpy(Item->title[9],"Necklace of fireballs type III");}
  else if(roll<74){strcpy(Item->title[9],"Circlet of persuasion");}
  else if(roll<75){strcpy(Item->title[9],"Slippers of spider climbing");}
  else if(roll<76){strcpy(Item->title[9],"ncense of meditation");}
  else if(roll<77){strcpy(Item->title[9],"Amulet of mighty fists +1");}
  else if(roll<78){strcpy(Item->title[9],"Bag of holding type II");}
  else if(roll<79){strcpy(Item->title[9],"Ioun stone, dusty rose prism");}
  else if(roll<81){strcpy(Item->title[9],"Helm of comprehend languages and read magic");}
  else if(roll<82){strcpy(Item->title[9],"Vest of escape");}
  else if(roll<83){strcpy(Item->title[9],"Eversmoking bottle");}
  else if(roll<84){strcpy(Item->title[9],"Sustaining spoon");}
  else if(roll<85){strcpy(Item->title[9],"Necklace of fireballs type IV");}
  else if(roll<86){strcpy(Item->title[9],"Boots of striding and springing");}
  else if(roll<87){strcpy(Item->title[9],"Wind fan");}
  else if(roll<88){strcpy(Item->title[9],"Necklace of fireballs type V");}
  else if(roll<89){strcpy(Item->title[9],"Horseshoes of a zephyr");}
  else if(roll<90){strcpy(Item->title[9],"Pipes of haunting");}
  else if(roll<91){strcpy(Item->title[9],"Gloves of swimming and climbing");}
  else if(roll<92){strcpy(Item->title[9],"Crown of blasting, minor");}
  else if(roll<93){strcpy(Item->title[9],"Horn of goodness/evil");}
  else if(roll<94){strcpy(Item->title[9],"Robe of useful items ");}
  else if(roll<95){strcpy(Item->title[9],"Boat, folding");}
  else if(roll<96){strcpy(Item->title[9],"Cloak of the manta ray");}
  else if(roll<97){strcpy(Item->title[9],"Bottle of air");}
  else if(roll<98){strcpy(Item->title[9],"Bag of holding type III");}
  else if(roll<99){strcpy(Item->title[9],"Periapt of health");}
  else if(roll<100){strcpy(Item->title[9],"Boots of levitation");}
  else if(roll>=100){strcpy(Item->title[9],"Harp of charming");}
  return;

}
void Table15_19(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<2){strcpy(Item->title[9],"Amulet of natural armor +2");}
  else if(roll<3){strcpy(Item->title[9],"Golem manual, flesh");}
  else if(roll<4){strcpy(Item->title[9],"Hand of glory");}
  else if(roll<5){strcpy(Item->title[9],"Ioun stone, deep red sphere");}
  else if(roll<6){strcpy(Item->title[9],"Ioun stone, incandescent blue sphere");}
  else if(roll<7){strcpy(Item->title[9],"Ioun stone, pale blue rhomboid");}
  else if(roll<8){strcpy(Item->title[9],"Ioun stone, pink and green sphere");}
  else if(roll<9){strcpy(Item->title[9],"Ioun stone, pink rhomboid");}
  else if(roll<10){strcpy(Item->title[9],"Ioun stone, scarlet and blue sphere");}
  else if(roll<11){strcpy(Item->title[9],"Deck of illusions");}
  else if(roll<12){strcpy(Item->title[9],"Necklace of fireballs type VI");}
  else if(roll<13){strcpy(Item->title[9],"Candle of invocation");}
  else if(roll<14){strcpy(Item->title[9],"Robe of blending");}
  else if(roll<15){strcpy(Item->title[9],"Bag of tricks, rust");}
  else if(roll<16){strcpy(Item->title[9],"Necklace of fireballs type VII");}
  else if(roll<17){strcpy(Item->title[9],"Bracers of armor +3");}
  else if(roll<18){strcpy(Item->title[9],"Cloak of resistance +3");}
  else if(roll<19){strcpy(Item->title[9],"Decanter of endless water");}
  else if(roll<20){strcpy(Item->title[9],"Necklace of adaptation");}
  else if(roll<21){strcpy(Item->title[9],"Pearl of power, 3rd-level spell");}
  else if(roll<22){strcpy(Item->title[9],"Figurine of wondrous power, serpentine owl");}
  else if(roll<23){strcpy(Item->title[9],"Strand of prayer beads, lesser");}
  else if(roll<24){strcpy(Item->title[9],"Bag of holding type IV");}
  else if(roll<25){strcpy(Item->title[9],"Belt of physical might +2");}
  else if(roll<26){strcpy(Item->title[9],"Figurine of wondrous power, bronze griffon");}
  else if(roll<27){strcpy(Item->title[9],"Figurine of wondrous power, ebony fly");}
  else if(roll<28){strcpy(Item->title[9],"Glove of storing");}
  else if(roll<29){strcpy(Item->title[9],"Headband of mental prowess +2");}
  else if(roll<30){strcpy(Item->title[9],"Ioun stone, dark blue rhomboid");}
  else if(roll<31){strcpy(Item->title[9],"Cape of the mountebank");}
  else if(roll<32){strcpy(Item->title[9],"Phylactery of negative channeling");}
  else if(roll<33){strcpy(Item->title[9],"Phylactery of positive channeling");}
  else if(roll<34){strcpy(Item->title[9],"Gauntlet of rust");}
  else if(roll<35){strcpy(Item->title[9],"Boots of speed");}
  else if(roll<36){strcpy(Item->title[9],"Goggles of night");}
  else if(roll<37){strcpy(Item->title[9],"Golem manual, clay");}
  else if(roll<38){strcpy(Item->title[9],"Medallion of thoughts");}
  else if(roll<39){strcpy(Item->title[9],"Blessed book");}
  else if(roll<40){strcpy(Item->title[9],"Gem of brightness");}
  else if(roll<41){strcpy(Item->title[9],"Lyre of building");}
  else if(roll<42){strcpy(Item->title[9],"Robe, Monk’s");}
  else if(roll<43){strcpy(Item->title[9],"Cloak of arachnida");}
  else if(roll<44){strcpy(Item->title[9],"Belt of dwarvenkind");}
  else if(roll<45){strcpy(Item->title[9],"Periapt of wound closure");}
  else if(roll<46){strcpy(Item->title[9],"Pearl of the sirines");}
  else if(roll<47){strcpy(Item->title[9],"Figurine of wondrous power, onyx dog");}
  else if(roll<48){strcpy(Item->title[9],"Bag of tricks, tan");}
  else if(roll<49){strcpy(Item->title[9],"Belt of giant strength +4");}
  else if(roll<50){strcpy(Item->title[9],"Belt of incredible dexterity +4");}
  else if(roll<51){strcpy(Item->title[9],"Belt of mighty constitution +4");}
  else if(roll<52){strcpy(Item->title[9],"Belt of physical perfection +2");}
  else if(roll<53){strcpy(Item->title[9],"Boots, winged");}
  else if(roll<54){strcpy(Item->title[9],"Bracers of armor +4");}
  else if(roll<55){strcpy(Item->title[9],"Cloak of resistance +4");}
  else if(roll<56){strcpy(Item->title[9],"Headband of alluring charisma +4");}
  else if(roll<57){strcpy(Item->title[9],"Headband of inspired wisdom +4");}
  else if(roll<58){strcpy(Item->title[9],"Headband of mental superiority +2");}
  else if(roll<59){strcpy(Item->title[9],"Headband of vast intelligence +4");}
  else if(roll<60){strcpy(Item->title[9],"Pearl of power, 4th-level spell");}
  else if(roll<61){strcpy(Item->title[9],"Scabbard of keen edges");}
  else if(roll<62){strcpy(Item->title[9],"Figurine of wondrous power, golden lions");}
  else if(roll<63){strcpy(Item->title[9],"Chime of interruption");}
  else if(roll<64){strcpy(Item->title[9],"Broom of flying");}
  else if(roll<65){strcpy(Item->title[9],"Figurine of wondrous power, marble elephant");}
  else if(roll<66){strcpy(Item->title[9],"Amulet of natural armor +3");}
  else if(roll<67){strcpy(Item->title[9],"Ioun stone, iridescent spindle");}
  else if(roll<68){strcpy(Item->title[9],"Bracelet of friends");}
  else if(roll<69){strcpy(Item->title[9],"Amulet of mighty fists +2");}
  else if(roll<70){strcpy(Item->title[9],"Carpet of flying, 5 ft. by 5 ft");}
  else if(roll<71){strcpy(Item->title[9],"Horn of blasting");}
  else if(roll<72){strcpy(Item->title[9],"Ioun stone, pale lavender ellipsoid");}
  else if(roll<73){strcpy(Item->title[9],"Ioun stone, pearly white spindle");}
  else if(roll<74){strcpy(Item->title[9],"Portable hole");}
  else if(roll<75){strcpy(Item->title[9],"Stone of good luck (luckstone)");}
  else if(roll<76){strcpy(Item->title[9],"Figurine of wondrous power, ivory goats");}
  else if(roll<77){strcpy(Item->title[9],"Rope of entanglement");}
  else if(roll<78){strcpy(Item->title[9],"Golem manual, stone");}
  else if(roll<79){strcpy(Item->title[9],"Mask of the skull");}
  else if(roll<81){strcpy(Item->title[9],"Mattock of the titans");}
  else if(roll<82){strcpy(Item->title[9],"Crown of blasting, major");}
  else if(roll<83){strcpy(Item->title[9],"Cloak of displacement, minor");}
  else if(roll<84){strcpy(Item->title[9],"Helm of underwater action");}
  else if(roll<85){strcpy(Item->title[9],"Bracers of archery, greater");}
  else if(roll<86){strcpy(Item->title[9],"Bracers of armor +5");}
  else if(roll<87){strcpy(Item->title[9],"Cloak of resistance +");}
  else if(roll<88){strcpy(Item->title[9],"Eyes of doom");}
  else if(roll<89){strcpy(Item->title[9],"Pearl of power, 5th-level spell");}
  else if(roll<90){strcpy(Item->title[9],"Maul of the titans");}
  else if(roll<91){strcpy(Item->title[9],"Cloak of the bat");}
  else if(roll<92){strcpy(Item->title[9],"Iron bands of binding");}
  else if(roll<93){strcpy(Item->title[9],"Cube of frost resistance");}
  else if(roll<94){strcpy(Item->title[9],"Helm of telepathy");}
  else if(roll<95){strcpy(Item->title[9],"Periapt of proof against poison");}
  else if(roll<96){strcpy(Item->title[9],"Robe of scintillating colors");}
  else if(roll<97){strcpy(Item->title[9],"Manual of bodily health +1");}
  else if(roll<98){strcpy(Item->title[9],"Manual of gainful exercise +1");}
  else if(roll<99){strcpy(Item->title[9],"Manual of quickness in action +1");}
  else if(roll<100){strcpy(Item->title[9],"Tome of clear thought +1");}
  else if(roll>=100){strcpy(Item->title[9],"Tome of leadership and influence +1");}
  return;
}
void Table15_20(Item_st *Item){
  int roll;
  printf("roll d100\n");
  scanf("%d",&roll );
  if(roll<2){strcpy(Item->title[9],"Dimensional shackles");}
  else if(roll<3){strcpy(Item->title[9],"Figurine of wondrous power, obsidian steed");}
  else if(roll<4){strcpy(Item->title[9],"Drums of panic");}
  else if(roll<5){strcpy(Item->title[9],"Ioun stone, orange prism");}
  else if(roll<6){strcpy(Item->title[9],"Ioun stone, pale green prism");}
  else if(roll<7){strcpy(Item->title[9],"Lantern of revealing");}
  else if(roll<8){strcpy(Item->title[9],"Amulet of natural armor +4");}
  else if(roll<9){strcpy(Item->title[9],"Amulet of proof against detection and location");}
  else if(roll<10){strcpy(Item->title[9],"Carpet of flying, 5 ft. by 10 ft.");}
  else if(roll<11){strcpy(Item->title[9],"Golem manual, iron");}
  else if(roll<12){strcpy(Item->title[9],"Belt of giant strength +6");}
  else if(roll<13){strcpy(Item->title[9],"Belt of incredible dexterity +6");}
  else if(roll<14){strcpy(Item->title[9],"Belt of mighty constitution +6");}
  else if(roll<15){strcpy(Item->title[9],"Bracers of armor +6");}
  else if(roll<16){strcpy(Item->title[9],"Headband of alluring charisma +6");}
  else if(roll<17){strcpy(Item->title[9],"Headband of inspired wisdom +6");}
  else if(roll<18){strcpy(Item->title[9],"Headband of vast intelligence +6");}
  else if(roll<19){strcpy(Item->title[9],"Ioun stone, vibrant purple prism");}
  else if(roll<20){strcpy(Item->title[9],"Pearl of power, 6th-level spell");}
  else if(roll<21){strcpy(Item->title[9],"Scarab of protection");}
  else if(roll<22){strcpy(Item->title[9],"Belt of physical might +4");}
  else if(roll<23){strcpy(Item->title[9],"Headband of mental prowess +4");}
  else if(roll<24){strcpy(Item->title[9],"Ioun stone, lavender and green ellipsoid");}
  else if(roll<25){strcpy(Item->title[9],"Ring gates");}
  else if(roll<26){strcpy(Item->title[9],"Crystal ball");}
  else if(roll<27){strcpy(Item->title[9],"Golem manual, stone guardian");}
  else if(roll<28){strcpy(Item->title[9],"Amulet of mighty fists +3");}
  else if(roll<29){strcpy(Item->title[9],"Strand of prayer beads");}
  else if(roll<30){strcpy(Item->title[9],"Orb of storms");}
  else if(roll<31){strcpy(Item->title[9],"Boots of teleportation");}
  else if(roll<32){strcpy(Item->title[9],"Bracers of armor +7");}
  else if(roll<33){strcpy(Item->title[9],"Pearl of power, 7th-level spell");}
  else if(roll<34){strcpy(Item->title[9],"Amulet of natural armor +5");}
  else if(roll<35){strcpy(Item->title[9],"Cloak of displacement, major");}
  else if(roll<36){strcpy(Item->title[9],"Crystal ball with see invisibility");}
  else if(roll<37){strcpy(Item->title[9],"Horn of Valhalla");}
  else if(roll<38){strcpy(Item->title[9],"Crystal ball with detect thoughts");}
  else if(roll<39){strcpy(Item->title[9],"Wings of flying");}
  else if(roll<40){strcpy(Item->title[9],"Cloak of etherealness");}
  else if(roll<41){strcpy(Item->title[9],"Instant fortress");}
  else if(roll<42){strcpy(Item->title[9],"Manual of bodily health +2");}
  else if(roll<43){strcpy(Item->title[9],"Manual of gainful exercise +2");}
  else if(roll<44){strcpy(Item->title[9],"Manual of quickness in action +2");}
  else if(roll<45){strcpy(Item->title[9],"Tome of clear thought +2");}
  else if(roll<46){strcpy(Item->title[9],"Tome of leadership and influence +2");}
  else if(roll<47){strcpy(Item->title[9],"Tome of understanding +2");}
  else if(roll<48){strcpy(Item->title[9],"Eyes of charming");}
  else if(roll<49){strcpy(Item->title[9],"Robe of stars");}
  else if(roll<50){strcpy(Item->title[9],"Carpet of flying, 10 ft. by 10 ft");}
  else if(roll<51){strcpy(Item->title[9],"Darkskull");}
  else if(roll<52){strcpy(Item->title[9],"Cube of force");}
  else if(roll<53){strcpy(Item->title[9],"Belt of physical perfection +4");}
  else if(roll<54){strcpy(Item->title[9],"Bracers of armor +8");}
  else if(roll<55){strcpy(Item->title[9],"Headband of mental superiority +4");}
  else if(roll<56){strcpy(Item->title[9],"Pearl of power, 8th-level spell");}
  else if(roll<57){strcpy(Item->title[9],"Crystal ball with telepathy");}
  else if(roll<58){strcpy(Item->title[9],"Horn of blasting, greater");}
  else if(roll<59){strcpy(Item->title[9],"Pearl of power, two spells");}
  else if(roll<60){strcpy(Item->title[9],"Helm of teleportation");}
  else if(roll<61){strcpy(Item->title[9],"Gem of seeing");}
  else if(roll<62){strcpy(Item->title[9],"Robe of the archmagi");}
  else if(roll<63){strcpy(Item->title[9],"Mantle of faith");}
  else if(roll<64){strcpy(Item->title[9],"Amulet of mighty fists +4");}
  else if(roll<65){strcpy(Item->title[9],"Crystal ball with true seeing");}
  else if(roll<66){strcpy(Item->title[9],"Pearl of power, 9th-level spell");}
  else if(roll<67){strcpy(Item->title[9],"Well of many worlds");}
  else if(roll<68){strcpy(Item->title[9],"Manual of bodily health +3");}
  else if(roll<69){strcpy(Item->title[9],"Manual of gainful exercise +3");}
  else if(roll<70){strcpy(Item->title[9],"Manual of quickness in action +3");}
  else if(roll<71){strcpy(Item->title[9],"Tome of clear thought +3");}
  else if(roll<72){strcpy(Item->title[9],"Tome of leadership and influence +3");}
  else if(roll<73){strcpy(Item->title[9],"Tome of understanding +3");}
  else if(roll<74){strcpy(Item->title[9],"Apparatus of the crab");}
  else if(roll<75){strcpy(Item->title[9],"Belt of physical might +6");}
  else if(roll<76){strcpy(Item->title[9],"Headband of mental prowess +6");}
  else if(roll<77){strcpy(Item->title[9],"Mantle of spell resistance");}
  else if(roll<78){strcpy(Item->title[9],"Mirror of opposition");}
  else if(roll<79){strcpy(Item->title[9],"Strand of prayer beads, greater");}
  else if(roll<81){strcpy(Item->title[9],"Manual of bodily health +4");}
  else if(roll<82){strcpy(Item->title[9],"Manual of gainful exercise +4");}
  else if(roll<83){strcpy(Item->title[9],"Manual of quickness in action +4");}
  else if(roll<84){strcpy(Item->title[9],"Tome of clear thought +4");}
  else if(roll<85){strcpy(Item->title[9],"Tome of leadership and influence +4");}
  else if(roll<86){strcpy(Item->title[9],"Tome of understanding +4");}
  else if(roll<87){strcpy(Item->title[9],"Amulet of the planes");}
  else if(roll<88){strcpy(Item->title[9],"Robe of eyes");}
  else if(roll<89){strcpy(Item->title[9],"Amulet of mighty fists +5");}
  else if(roll<90){strcpy(Item->title[9],"Helm of brilliance");}
  else if(roll<91){strcpy(Item->title[9],"Manual of bodily health +5");}
  else if(roll<92){strcpy(Item->title[9],"Manual of gainful exercise +5");}
  else if(roll<93){strcpy(Item->title[9],"Manual of quickness in action +5");}
  else if(roll<94){strcpy(Item->title[9],"Tome of clear thought +5");}
  else if(roll<95){strcpy(Item->title[9],"Tome of leadership and influence +5");}
  else if(roll<96){strcpy(Item->title[9],"Tome of understanding +5");}
  else if(roll<97){strcpy(Item->title[9],"Belt of physical perfection +6");}
  else if(roll<98){strcpy(Item->title[9],"Headband of mental superiority +6");}
  else if(roll<99){strcpy(Item->title[9],"Efreeti bottle");}
  else if(roll<100){strcpy(Item->title[9],"Cubic gate");}
  else if(roll>=100){strcpy(Item->title[9],"Mirror of life trapping");}
  return;
}
int Table5_2(Item_st *Item, int Tier,int roll){
  if (Tier==1) {
    if(roll<26){table6_9(10);}
    else if(roll<37){table6_9(50);}
    else if(roll<43){table6_9(100);}
    else if(roll<47){table6_9(101);}
    else if(roll<57){Table5_4(Item);}
    else if(roll<70){Table5_11(Item);}
    else if(roll<78){Table5_19(Item, Tier);}
    else if(roll<84){Table5_24(Item, Tier);}
    else if(roll<89){Table15_18(Item);}
    else if(roll<92){/*Table5_4 M armor or shield*/}
    else if(roll<97){/*Table5_11 M weapon*/}
    else if(roll<99){/*Table5_47 wand*/}
    else if(roll>=99){/*Table15_13 ring*/}
  }
  if (Tier==2) {
    if(roll<6){table6_9(100);}
    else if(roll<17){table6_9(101);}
    else if(roll<20){/*Table5_4 armor or shield*/}
    else if(roll<24){/*Table5_11 weapon*/}
    else if(roll<36){/*Table5_19 potion*/}
    else if(roll<46){/*Table5_24 scroll*/}
    else if(roll<54){/*Table15_18 minor wonder*/}
    else if(roll<69){/*Table5_4 M armor or shield*/}
    else if(roll<84){/*Table5_11 M weapon*/}
    else if(roll<92){/*Table5_47 wand*/}
    else if(roll<96){/*Table15_13 ring*/}
    else if(roll>=96){/*Table15_19 mid wonder*/}
  }
  if (Tier==3) {
    if(roll<11){/*Table5_19 potion*/}
    else if(roll<17){/*Table5_24 scroll*/}
    else if(roll<23){/*Table15_18 minor wonder*/}
    else if(roll<27){/*Table5_4 M armor or shield*/}
    else if(roll<39){/*Table5_11 M weapon*/}
    else if(roll<57){/*Table5_47 wand*/}
    else if(roll<67){/*Table15_13 ring*/}
    else if(roll<75){/*Table15_19 mid wonder*/}
    else if(roll<85){/*Table15_14 rod*/}
    else if(roll<95){/*Table15_16 staf*/}
    else if(roll>=95){/*Table15_20 major wonder*/}
  }
  return 0;
}


int main() {
  TabC=0;
  int Tier;
  Item_st Item;
  int roll;
  strcpy(Item.title[1],"");
  printf("Lootbox tier(1-3)\n");
  scanf("%d",&Tier);
  printf("roll d100\n");
  scanf("%d",&Item.rolls[TabC]);
  roll=Item.rolls[TabC];
  Table5_2(&Item,Tier,roll);

  for (int i = 0; i < 1; i++) {
    printf("%d=  %s\n",i,Item.title[i]);
  }

  return 0;
 }
