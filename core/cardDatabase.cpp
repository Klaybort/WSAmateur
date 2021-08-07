#include "cardDatabase.h"

CardDatabase::CardDatabase() {
    auto info = std::make_shared<CardInfo>();
    info->setCode("IMC/W43-009");
    info->setLevel(0);
    info->setCost(0);
    info->setSoul(1);
    info->setPower(4000);
    info->setName("prr");
    info->setType(CardType::Char);
    info->setColor('Y');
    info->setTraits({ "Music", "Happy Happy" });
    mDb.emplace(info->code(), info);

    auto info2 = std::make_shared<CardInfo>();
    info2->setCode("IMC/W43-046");
    info2->setLevel(0);
    info2->setCost(0);
    info2->setSoul(1);
    info2->setPower(1500);
    info2->setName("prru");
    info2->setType(CardType::Char);
    info2->setColor('R');
    mDb.emplace(info2->code(), info2);

    auto info100500 = std::make_shared<CardInfo>();
    info100500->setCode("KGL/S79-055");
    info100500->setLevel(0);
    info100500->setCost(0);
    info100500->setSoul(1);
    info100500->setPower(1500);
    info100500->setName("prru");
    info100500->setType(CardType::Char);
    info100500->setColor('R');
    info100500->setTraits({ "Music" });
    mDb.emplace(info100500->code(), info100500);

    auto info3 = std::make_shared<CardInfo>();
    info3->setCode("IMC/W43-111");
    info3->setLevel(1);
    info3->setCost(0);
    info3->setSoul(1);
    info3->setPower(5000);
    info3->setName("prru");
    info3->setType(CardType::Char);
    info3->setColor('B');
    info3->setTraits({ "Music" });
    mDb.emplace(info3->code(), info3);

    auto info4 = std::make_shared<CardInfo>();
    info4->setCode("IMC/W43-091");
    info4->setLevel(3);
    info4->setCost(2);
    info4->setSoul(2);
    info4->setPower(10000);
    info4->setName("prru");
    info4->setType(CardType::Char);
    info4->setColor('B');
    info4->setTraits({ "Music" });
    info4->setTriggers({ TriggerIcon::Soul });
    mDb.emplace(info4->code(), info4);

    auto info5 = std::make_shared<CardInfo>();
    info5->setCode("IMC/W43-127");
    info5->setLevel(0);
    info5->setCost(0);
    info5->setSoul(0);
    info5->setPower(0);
    info5->setName("花火の音は聞こえない");
    info5->setType(CardType::Climax);
    info5->setColor('G');
    info5->setTriggers({ TriggerIcon::Bag });
    mDb.emplace(info5->code(), info5);

    auto info6 = std::make_shared<CardInfo>();
    info6->setCode("KGL/S79-001");
    info6->setLevel(0);
    info6->setCost(0);
    info6->setSoul(1);
    info6->setPower(1000);
    info6->setName("ラブ探偵");
    info6->setType(CardType::Char);
    info6->setColor('Y');
    info6->setTraits({ "Shuchiin", "Secretary" });
    //info6->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x06, 0x01, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    //info6->addAbility({0x02, 0x05, 0x00, 0x01, 0x02, 0x01, 0x02, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, 0x04, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x06, 0x00, 0x04, 0x05, 0x00, 0x01, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01, 0x06, 0x02, 0x02, 0x00, 0x03, 0x01, 0x03, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x24, 0x00, 0x03, 0x01, 0x00, 0x00});
    mDb.emplace(info6->code(), info6);

    auto info7 = std::make_shared<CardInfo>();
    info7->setCode("KGL/S79-021");
    info7->setLevel(0);
    info7->setCost(0);
    info7->setSoul(0);
    info7->setPower(0);
    info7->setName("ヨー！メーン♪");
    info7->setType(CardType::Climax);
    info7->setColor('Y');
    info7->setTriggers({ TriggerIcon::Choice });
    info7->addAbility({0x01, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info7->code(), info7);

    auto info8 = std::make_shared<CardInfo>();
    info8->setCode("KGL/S79-002");
    info8->setLevel(0);
    info8->setCost(0);
    info8->setSoul(1);
    info8->setPower(4500);
    info8->setName("pruu");
    info8->setType(CardType::Char);
    info8->setColor('Y');
    info8->setTraits({ "Shuchiin" });
    //info8->addAbility({0x01, 0x03, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x00, 0x00});
    //info8->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x04, 0x15, 0xe3, 0x83, 0xa8, 0xe3, 0x83, 0xbc, 0xef, 0xbc, 0x81, 0xe3, 0x83, 0xa1, 0xe3, 0x83, 0xbc, 0xe3, 0x83, 0xb3, 0xe2, 0x99, 0xaa, 0x00, 0x09, 0x03, 0x01, 0x07, 0x02, 0x00, 0x01, 0x03, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x05, 0x00, 0x02, 0x04, 0x01, 0x03, 0x03, 0x02, 0x00, 0x01, 0x03, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x09, 0x02, 0x00, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x01, 0x00, 0x02, 0x05, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x02, 0x01, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00});
    mDb.emplace(info8->code(), info8);

    auto info9 = std::make_shared<CardInfo>();
    info9->setCode("KGL/S79-003");
    info9->setLevel(0);
    info9->setCost(0);
    info9->setSoul(1);
    info9->setPower(2500);
    info9->setName("pruu");
    info9->setType(CardType::Char);
    info9->setColor('Y');
    info9->setTraits({ "Shuchiin" });
    info9->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x06, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x04, 0x0c, 0xe3, 0x83, 0xa9, 0xe3, 0x83, 0x96, 0xe6, 0x8e, 0xa2, 0xe5, 0x81, 0xb5, 0x00, 0x02, 0x00, 0x02, 0x01, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x00});
    mDb.emplace(info9->code(), info9);

    auto info10 = std::make_shared<CardInfo>();
    info10->setCode("KGL/S79-004");
    info10->setLevel(0);
    info10->setCost(0);
    info10->setSoul(2);
    info10->setPower(6000);
    info10->setName("pruu");
    info10->setType(CardType::Char);
    info10->setColor('Y');
    info10->setTraits({ "Shuchiin" });
    info10->addAbility({0x01, 0x03, 0x01, 0x01, 0x02, 0x00, 0x01, 0x03, 0x04, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x40, 0x1f, 0x00, 0x00, 0x00, 0x00});
    info10->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x06, 0x00, 0x01, 0x08, 0x00, 0x03, 0x00, 0x00});
    mDb.emplace(info10->code(), info10);

    auto info11 = std::make_shared<CardInfo>();
    info11->setCode("KGL/S79-005");
    info11->setLevel(0);
    info11->setCost(0);
    info11->setSoul(2);
    info11->setPower(2000);
    info11->setName("pruu");
    info11->setType(CardType::Char);
    info11->setColor('Y');
    info11->setTraits({ "Shuchiin" });
    info11->addAbility({0x01, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x02, 0xd0, 0x07, 0x00, 0x00, 0x01, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x01, 0x02, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x00, 0x00});
    info11->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03, 0x01, 0x06, 0x00, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x08, 0x01, 0x01, 0x01, 0x00, 0x00});
    mDb.emplace(info11->code(), info11);

    auto info12 = std::make_shared<CardInfo>();
    info12->setCode("KGL/S79-006");
    info12->setLevel(0);
    info12->setCost(0);
    info12->setSoul(2);
    info12->setPower(2000);
    info12->setName("pruu");
    info12->setType(CardType::Char);
    info12->setColor('Y');
    info12->setTraits({ "Shuchiin" });
    info12->addAbility({0x01, 0x03, 0x01, 0x01, 0x02, 0x00, 0x01, 0x03, 0x04, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x00, 0x00});
    info12->addAbility({0x01, 0x03, 0x01, 0x01, 0x00, 0x08, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00});
    info12->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x04, 0x01, 0x03, 0x01, 0x06, 0x03, 0x02, 0x02, 0x00, 0x01, 0x01, 0x02, 0x01, 0x04, 0x12, 0xe3, 0x83, 0xa9, 0xe3, 0x83, 0xbc, 0xe3, 0x83, 0xa1, 0xe3, 0x83, 0xb3, 0xe5, 0x96, 0xb0, 0xe3, 0x81, 0x84, 0x00, 0x09, 0x01, 0x00, 0x02, 0x00, 0x01, 0x03, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x02, 0x01, 0x0d, 0x00, 0x01, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x04, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info12->code(), info12);

    auto info13 = std::make_shared<CardInfo>();
    info13->setCode("KGL/S79-022");
    info13->setLevel(0);
    info13->setCost(0);
    info13->setSoul(0);
    info13->setPower(0);
    info13->setName("ラーメン喰い");
    info13->setType(CardType::Climax);
    info13->setColor('Y');
    info13->setTriggers({ TriggerIcon::Choice });
    info13->addAbility({0x01, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info13->code(), info13);

    auto info14 = std::make_shared<CardInfo>();
    info14->setCode("KGL/S79-007");
    info14->setLevel(0);
    info14->setCost(0);
    info14->setSoul(1);
    info14->setPower(500);
    info14->setName("ラーメン喰");
    info14->setType(CardType::Char);
    info14->setColor('Y');
    info14->setTraits({ "Shuchiin" });
    info14->addAbility({0x02, 0x05, 0x00, 0x02, 0x04, 0x01, 0x03, 0x02, 0x02, 0x00, 0x01, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    info14->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x08, 0x01, 0x07, 0x02, 0x03, 0x01, 0x06, 0x00, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x06, 0x01, 0x01, 0x01, 0x00, 0x00});
    mDb.emplace(info14->code(), info14);

    auto info15 = std::make_shared<CardInfo>();
    info15->setCode("KGL/S79-008");
    info15->setLevel(0);
    info15->setCost(0);
    info15->setSoul(1);
    info15->setPower(1000);
    info15->setName("ラーメン喰");
    info15->setType(CardType::Char);
    info15->setColor('Y');
    info15->setTraits({ "Shuchiin" });
    info15->addAbility({0x01, 0x03, 0x01, 0x01, 0x00, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x02, 0x01, 0x01, 0x01, 0xe8, 0x03, 0x00, 0x00, 0x00, 0x00});
    info15->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x03, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x01, 0x00, 0x06, 0x02, 0x00, 0x04, 0x00, 0x02, 0x09, 0x00, 0x06, 0x02, 0x01, 0x00, 0x01, 0x02, 0x00, 0x00});
    mDb.emplace(info15->code(), info15);

    auto info16 = std::make_shared<CardInfo>();
    info16->setCode("KGL/S79-009");
    info16->setLevel(0);
    info16->setCost(0);
    info16->setSoul(1);
    info16->setPower(1000);
    info16->setName("ラーメン喰");
    info16->setType(CardType::Char);
    info16->setColor('Y');
    info16->setTraits({ "Shuchiin" });
    info16->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x04, 0x02, 0x00, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x00});
    info16->addAbility({0x03, 0x04, 0x01, 0x03, 0x01, 0x02, 0x01, 0x02, 0x02, 0x11, 0x00, 0x01, 0x02, 0x03, 0x01, 0x09, 0x00, 0x01, 0x08, 0x01, 0x01, 0x02, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x02, 0x00, 0x02, 0x01, 0x04, 0x00, 0x01, 0x02, 0x00, 0x02, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00});
    mDb.emplace(info16->code(), info16);

    auto info17 = std::make_shared<CardInfo>();
    info17->setCode("KGL/S79-010");
    info17->setLevel(0);
    info17->setCost(0);
    info17->setSoul(1);
    info17->setPower(2500);
    info17->setName("ラーメン喰");
    info17->setType(CardType::Char);
    info17->setColor('Y');
    info17->setCounter(true);
    info17->setTraits({ "Shuchiin" });
    //info17->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x04, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x06, 0x03, 0x01, 0x06, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x02, 0x01, 0x01, 0x07, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02, 0x01, 0x00, 0x00});
    info17->addAbility({0x03, 0x04, 0x01, 0x04, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x03, 0x01, 0x0a, 0x00, 0xd0, 0x07, 0x00, 0x00, 0x02, 0x00});
    mDb.emplace(info17->code(), info17);

    auto info18 = std::make_shared<CardInfo>();
    info18->setCode("KGL/S79-011");
    info18->setLevel(4);
    info18->setCost(0);
    info18->setSoul(1);
    info18->setPower(4000);
    info18->setName("ラブ探偵");
    info18->setType(CardType::Char);
    info18->setColor('Y');
    info18->setTraits({ "Shuchiin" });
    info18->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x01, 0x03, 0x01, 0x06, 0x00, 0x01, 0x0b, 0x00, 0x00, 0x00});
    mDb.emplace(info18->code(), info18);

    auto info19 = std::make_shared<CardInfo>();
    info19->setCode("KGL/S79-012");
    info19->setLevel(0);
    info19->setCost(0);
    info19->setSoul(1);
    info19->setPower(4000);
    info19->setName("ラーメン喰");
    info19->setType(CardType::Char);
    info19->setColor('Y');
    info19->setTraits({ "Shuchiin" });
    info19->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x04, 0x0c, 0x00, 0x02, 0x06, 0x01, 0x03, 0x01, 0x04, 0x00, 0x01, 0x06, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x01, 0x00, 0x05, 0x02, 0x00, 0x00});
    info19->addAbility({0x03, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x04, 0x0c, 0xe3, 0x83, 0xa9, 0xe3, 0x83, 0x96, 0xe6, 0x8e, 0xa2, 0xe5, 0x81, 0xb5, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x03, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x04, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    mDb.emplace(info19->code(), info19);

    auto info20 = std::make_shared<CardInfo>();
    info20->setCode("KGL/S79-013");
    info20->setLevel(0);
    info20->setCost(0);
    info20->setSoul(1);
    info20->setPower(4000);
    info20->setName("ラーメン喰");
    info20->setType(CardType::Char);
    info20->setColor('Y');
    info20->setTraits({ "Shuchiin" });
    info20->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x02, 0x04, 0x01, 0x06, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x01, 0x03, 0x01, 0x06, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x00});
    info20->addAbility({0x02, 0x05, 0x00, 0x02, 0x03, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x00, 0x04, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x04, 0x00, 0x02, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x03, 0x02, 0x01, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00});
    mDb.emplace(info20->code(), info20);

    auto info21 = std::make_shared<CardInfo>();
    info21->setCode("KGL/S79-014");
    info21->setLevel(0);
    info21->setCost(0);
    info21->setSoul(1);
    info21->setPower(2000);
    info21->setName("ラーメン喰");
    info21->setType(CardType::Char);
    info21->setColor('Y');
    info21->setTraits({ "Shuchiin" });
    info21->addAbility({0x02, 0x05, 0x00, 0x02, 0x04, 0x01, 0x03, 0x02, 0x02, 0x00, 0x01, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x02, 0xe8, 0x03, 0x00, 0x00, 0x01, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x01, 0x02, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x01, 0x00});
    mDb.emplace(info21->code(), info21);

    auto info22 = std::make_shared<CardInfo>();
    info22->setCode("KGL/S79-015");
    info22->setLevel(0);
    info22->setCost(0);
    info22->setSoul(1);
    info22->setPower(5000);
    info22->setName("想いを馳せる千花");
    info22->setType(CardType::Char);
    info22->setColor('Y');
    info22->setTraits({ "Shuchiin" });
    info22->addAbility({0x02, 0x05, 0x00, 0x02, 0x03, 0x03, 0x01, 0x0d, 0x01, 0x05, 0x01, 0x01, 0x07, 0x01, 0x04, 0x00, 0x01, 0x05, 0x00, 0x01, 0x02, 0x01, 0x00, 0x07, 0x02, 0x00, 0x01, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x02, 0x07, 0x02, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00});
    mDb.emplace(info22->code(), info22);

    auto info23 = std::make_shared<CardInfo>();
    info23->setCode("KGL/S79-016");
    info23->setLevel(0);
    info23->setCost(0);
    info23->setSoul(1);
    info23->setPower(2000);
    info23->setName("ラーメン喰");
    info23->setType(CardType::Char);
    info23->setColor('Y');
    info23->setTraits({ "Shuchiin" });
    info23->addAbility({0x01, 0x04, 0x01, 0x0b, 0x03, 0x01, 0x01, 0x00, 0x03, 0x03, 0x01, 0x00, 0x02, 0x01, 0x01, 0x06, 0x03, 0x06, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x00, 0x00});
    info23->addAbility({0x02, 0x05, 0x00, 0x02, 0xff, 0x0b, 0x4b, 0x47, 0x4c, 0x2f, 0x53, 0x37, 0x39, 0x2d, 0x30, 0x31, 0x36, 0x03, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    mDb.emplace(info23->code(), info23);

    auto info24 = std::make_shared<CardInfo>();
    info24->setCode("KGL/S79-017");
    info24->setLevel(1);
    info24->setCost(0);
    info24->setSoul(1);
    info24->setPower(2000);
    info24->setName("ラーメン喰");
    info24->setType(CardType::Char);
    info24->setColor('Y');
    info24->setTraits({ "Shuchiin" });
    info24->addAbility({0x01, 0x03, 0x01, 0x0e, 0x02, 0x00, 0x01, 0x03, 0x08, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x00, 0x00});
    info24->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x04, 0x01, 0x03, 0x01, 0x06, 0x03, 0x02, 0x02, 0x00, 0x01, 0x01, 0x02, 0x01, 0x04, 0x15, 0xe5, 0xa3, 0x8a, 0xe3, 0x82, 0x8c, 0xe3, 0x81, 0x9f, 0xe3, 0x83, 0x96, 0xe3, 0x83, 0xac, 0xe3, 0x83, 0xbc, 0xe3, 0x82, 0xad, 0x00, 0x09, 0x01, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x04, 0x05, 0x00, 0x01, 0x02, 0x04, 0x01, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x03, 0x01, 0x03, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x24, 0x00, 0x03, 0x01, 0x00, 0x00});
    mDb.emplace(info24->code(), info24);

    auto info25 = std::make_shared<CardInfo>();
    info25->setCode("KGL/S79-018");
    info25->setLevel(0);
    info25->setCost(0);
    info25->setSoul(0);
    info25->setPower(0);
    info25->setName("ラブ探偵");
    info25->setType(CardType::Event);
    info25->setColor('Y');
    //info25->addAbility({0x01, 0x03, 0x01, 0x0f, 0x02, 0x01, 0x01, 0x03, 0x02, 0x02, 0x01, 0x01, 0x05, 0x06, 0xe5, 0x8d, 0x83, 0xe8, 0x8a, 0xb1, 0x00, 0x01, 0x01, 0x00, 0x00});
    //info25->addAbility({0x04, 0x03, 0x05, 0x0c, 0x00, 0x02, 0x08, 0x01, 0x03, 0x01, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x03, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x04, 0x00, 0x01, 0x04, 0x00, 0x00, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x00});
    //info25->addAbility({0x04, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x09, 0x02, 0x00, 0x00, 0x02, 0x03, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info25->code(), info25);

    auto info26 = std::make_shared<CardInfo>();
    info26->setCode("KGL/S79-019");
    info26->setLevel(0);
    info26->setCost(0);
    info26->setSoul(0);
    info26->setPower(0);
    info26->setName("ラーメン喰");
    info26->setType(CardType::Event);
    info26->setColor('Y');
    info26->addAbility({0x04, 0x03, 0x01, 0x10, 0x00, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x00, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x03, 0x02, 0x00, 0x01, 0x03, 0x00, 0x02, 0x0a, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x01, 0x00, 0x06, 0x02, 0x00, 0x04, 0x00, 0x02, 0x09, 0x00, 0x06, 0x02, 0x01, 0x07, 0x01, 0x02, 0x00, 0x00, 0x03, 0x01, 0x04, 0x02, 0x00, 0x02, 0x03, 0x0a, 0x00, 0x00, 0x06, 0x02, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x06, 0x02, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00});
    //info26->addAbility({0x04, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x09, 0x02, 0x00, 0x00, 0x02, 0x03, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info26->code(), info26);

    auto info27 = std::make_shared<CardInfo>();
    info27->setCode("KGL/S79-666");
    info27->setLevel(0);
    info27->setCost(0);
    info27->setSoul(1);
    info27->setPower(4000);
    info27->setName("ラーメン喰");
    info27->setType(CardType::Char);
    info27->setColor('Y');
    info27->addAbility({0x02, 0x05, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x12, 0x00, 0x01, 0x01, 0x00});
    mDb.emplace(info27->code(), info27);

    auto info28 = std::make_shared<CardInfo>();
    info28->setCode("KGL/S79-020");
    info28->setLevel(0);
    info28->setCost(0);
    info28->setSoul(0);
    info28->setPower(0);
    info28->setName("ラーメン喰");
    info28->setType(CardType::Event);
    info28->setColor('Y');
    //info28->addAbility({0x04, 0x03, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x70, 0x17, 0x00, 0x00, 0x01, 0x00});
    info28->addAbility({0x04, 0x03, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x07, 0x01, 0x00, 0x00});
    //info28->addAbility({0x04, 0x03, 0x01, 0xff, 0x00, 0x0b, 0x4b, 0x47, 0x4c, 0x2f, 0x53, 0x37, 0x39, 0x2d, 0x30, 0x32, 0x30, 0x06, 0x00});
    mDb.emplace(info28->code(), info28);

    auto info29 = std::make_shared<CardInfo>();
    info29->setCode("KGL/S79-024");
    info29->setLevel(0);
    info29->setCost(0);
    info29->setSoul(1);
    info29->setPower(3000);
    info29->setName("ラーメン喰");
    info29->setType(CardType::Char);
    info29->setColor('G');
    info29->setTraits({ "Shuchiin" });
    info29->addAbility({0x02, 0x05, 0x00, 0x02, 0x05, 0x00, 0x03, 0x03, 0x02, 0x00, 0x01, 0x01, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x02, 0x00, 0x01, 0x01, 0x11, 0x00, 0x02, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x01, 0x01, 0x01, 0x06, 0x01, 0x01, 0x00, 0x00});
    info29->addAbility({0x02, 0x05, 0x00, 0x02, 0x08, 0x01, 0x07, 0x02, 0x03, 0x02, 0x0d, 0x00, 0x01, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x01, 0x09, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x04, 0x0f, 0xe6, 0x81, 0x8b, 0xe6, 0x84, 0x9b, 0xe9, 0xa0, 0xad, 0xe8, 0x84, 0xb3, 0xe6, 0x88, 0xa6, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info29->code(), info29);

    auto info30 = std::make_shared<CardInfo>();
    info30->setCode("KGL/S79-025");
    info30->setLevel(0);
    info30->setCost(0);
    info30->setSoul(1);
    info30->setPower(3000);
    info30->setName("不安と期待 かぐや");
    info30->setType(CardType::Char);
    info30->setColor('G');
    info30->setTraits({ "Shuchiin" });
    info30->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x0d, 0x00, 0x01, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x04, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00});
    info30->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x01, 0x02, 0x01, 0x06, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x04, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x06, 0x02, 0x00, 0x01, 0x01, 0x02, 0x01, 0x04, 0x12, 0xe7, 0xa4, 0xbe, 0xe4, 0xbc, 0x9a, 0xe3, 0x81, 0xb8, 0xe3, 0x81, 0xae, 0xe5, 0x8f, 0x9b, 0xe9, 0x80, 0x86, 0x00, 0x09, 0x01, 0x00, 0x01, 0x10, 0x00, 0x01, 0x02, 0x01, 0x03, 0x01, 0x12, 0x00, 0x02, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x04, 0x0c, 0xe3, 0x83, 0xa9, 0xe3, 0x83, 0x96, 0xe6, 0x8e, 0xa2, 0xe5, 0x81, 0xb5, 0x02, 0x00, 0x00, 0x00});
    mDb.emplace(info30->code(), info30);

    auto info31 = std::make_shared<CardInfo>();
    info31->setCode("KGL/S79-026");
    info31->setLevel(0);
    info31->setCost(0);
    info31->setSoul(1);
    info31->setPower(3000);
    info31->setName("ラーメン喰");
    info31->setType(CardType::Char);
    info31->setColor('G');
    info31->setTraits({ "Shuchiin" });
    info31->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x07, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x13, 0x05, 0x01, 0x03, 0x00, 0x00, 0x02, 0x00});
    info31->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x05, 0x01, 0x02, 0x01, 0x04, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x06, 0x06, 0x03, 0x01, 0x04, 0x00, 0x01, 0x05, 0x00, 0x01, 0x02, 0x01, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00});
    mDb.emplace(info31->code(), info31);

    auto info32 = std::make_shared<CardInfo>();
    info32->setCode("KGL/S79-027");
    info32->setLevel(0);
    info32->setCost(0);
    info32->setSoul(1);
    info32->setPower(3000);
    info32->setName("ラーメン喰");
    info32->setType(CardType::Char);
    info32->setColor('G');
    info32->setTraits({ "Shuchiin" });
    //info32->addAbility({0x02, 0x05, 0x00, 0x02, 0x08, 0x01, 0x03, 0x02, 0x03, 0x02, 0x03, 0x00, 0x01, 0x01, 0x02, 0x0d, 0x01, 0x06, 0x01, 0x01, 0x06, 0x03, 0x02, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info32->code(), info32);

    auto info33 = std::make_shared<CardInfo>();
    info33->setCode("KGL/S79-028");
    info33->setLevel(0);
    info33->setCost(0);
    info33->setSoul(1);
    info33->setPower(3000);
    info33->setName("ラーメン喰");
    info33->setType(CardType::Char);
    info33->setColor('G');
    info33->setTraits({ "Shuchiin" });
    //info33->addAbility({0x02, 0x05, 0x00, 0x02, 0x07, 0x01, 0x01, 0x02, 0x03, 0x02, 0x03, 0x00, 0x01, 0x01, 0x02, 0x0d, 0x01, 0x06, 0x01, 0x01, 0x06, 0x03, 0x02, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00});
    info33->addAbility({0x02, 0x05, 0x01, 0x02, 0x07, 0x01, 0x01, 0x02, 0x03, 0x02, 0x03, 0x00, 0x01, 0x01, 0x02, 0x0d, 0x01, 0x06, 0x01, 0x01, 0x06, 0x03, 0x02, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info33->code(), info33);

    auto info34 = std::make_shared<CardInfo>();
    info34->setCode("KGL/S79-029");
    info34->setLevel(0);
    info34->setCost(0);
    info34->setSoul(1);
    info34->setPower(3000);
    info34->setName("ラーメン喰");
    info34->setType(CardType::Char);
    info34->setColor('G');
    info34->setTraits({ "Shuchiin" });
    info34->addAbility({0x01, 0x04, 0x01, 0x0b, 0x03, 0x01, 0x01, 0x00, 0x03, 0x03, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x00, 0x00});
    info34->addAbility({0x02, 0x05, 0x01, 0x02, 0x02, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x03, 0x03, 0x02, 0x03, 0x00, 0x01, 0x01, 0x02, 0x0d, 0x01, 0x06, 0x01, 0x01, 0x06, 0x03, 0x02, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info34->code(), info34);

    auto info35 = std::make_shared<CardInfo>();
    info35->setCode("KGL/S79-034");
    info35->setLevel(0);
    info35->setCost(0);
    info35->setSoul(1);
    info35->setPower(3000);
    info35->setName("ラーメン喰");
    info35->setType(CardType::Char);
    info35->setColor('G');
    info35->setTraits({ "Shuchiin" });
    info35->addAbility({0x01, 0x03, 0x02, 0x01, 0x02, 0x00, 0x01, 0x03, 0x04, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xb8, 0x0b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x01, 0x01, 0x01, 0x02, 0x05, 0x00, 0x04, 0x01, 0x01, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03, 0x01, 0x06, 0x00, 0x01, 0x04, 0x00, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x08, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00});
    info35->addAbility({0x02, 0x05, 0x01, 0x02, 0x02, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    mDb.emplace(info35->code(), info35);

    auto info36 = std::make_shared<CardInfo>();
    info36->setCode("KGL/S79-035");
    info36->setLevel(0);
    info36->setCost(0);
    info36->setSoul(1);
    info36->setPower(3000);
    info36->setName("Kei, Killing Hello Return");
    info36->setType(CardType::Char);
    info36->setCounter(true);
    info36->setColor('G');
    info36->setTraits({ "Shuchiin" });
    //info36->addAbility({0x01, 0x03, 0x01, 0x01, 0x00, 0x03, 0x03, 0x01, 0x00, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x02, 0xe8, 0x03, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00});
    //info36->addAbility({0x03, 0x01, 0x01, 0x02, 0x11, 0x00, 0x03, 0x00, 0x01, 0x04, 0x03, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x02, 0x01, 0x02, 0x03, 0x01, 0x15, 0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x00, 0x08, 0x01, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00, 0x02, 0x00, 0x02, 0x01, 0x00});
    mDb.emplace(info36->code(), info36);

    auto info37 = std::make_shared<CardInfo>();
    info37->setCode("KGL/S79-037");
    info37->setLevel(0);
    info37->setCost(0);
    info37->setSoul(1);
    info37->setPower(3000);
    info37->setName("ラーメン喰");
    info37->setType(CardType::Char);
    info37->setColor('G');
    info37->setTraits({ "Shuchiin" });
    info37->addAbility({0x01, 0x03, 0x02, 0x01, 0x00, 0x03, 0x01, 0x00, 0x00, 0x01, 0x04, 0x19, 0x4b, 0x65, 0x69, 0x2c, 0x20, 0x4b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x52, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x03, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x03, 0x01, 0x00, 0x00, 0x01, 0x04, 0x19, 0x4b, 0x65, 0x69, 0x2c, 0x20, 0x4b, 0x69, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x52, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x08, 0x01, 0x01, 0x01, 0x02, 0xe8, 0x03, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00});
    mDb.emplace(info37->code(), info37);

    auto info38 = std::make_shared<CardInfo>();
    info38->setCode("KGL/S79-038");
    info38->setLevel(0);
    info38->setCost(0);
    info38->setSoul(1);
    info38->setPower(3000);
    info38->setName("ラーメン喰");
    info38->setType(CardType::Char);
    info38->setColor('G');
    info38->setTraits({ "Shuchiin" });
    info38->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x02, 0x03, 0x02, 0x01, 0x02, 0x03, 0x01, 0x01, 0x02, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x05, 0x01, 0x03, 0x01, 0x0d, 0x00, 0x01, 0x0c, 0x00, 0x01, 0x02, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00});
    mDb.emplace(info38->code(), info38);

    auto info39 = std::make_shared<CardInfo>();
    info39->setCode("KGL/S79-040");
    info39->setLevel(0);
    info39->setCost(0);
    info39->setSoul(1);
    info39->setPower(3000);
    info39->setName("ラーメン喰");
    info39->setType(CardType::Char);
    info39->setColor('G');
    info39->setTraits({ "Shuchiin" });
    //info39->addAbility({0x02, 0x05, 0x00, 0x02, 0x08, 0x01, 0x06, 0x01, 0x03, 0x01, 0x0d, 0x00, 0x01, 0x04, 0x00, 0x02, 0x03, 0x00, 0x01, 0x04, 0x00, 0x01, 0x07, 0x02, 0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x16, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00});
    mDb.emplace(info39->code(), info39);

    auto info40 = std::make_shared<CardInfo>();
    info40->setCode("KGL/S79-044");
    info40->setLevel(0);
    info40->setCost(0);
    info40->setSoul(0);
    info40->setPower(0);
    info40->setName("ラーメン喰");
    info40->setType(CardType::Event);
    info40->setColor('G');
    info40->setCounter(true);
    info40->addAbility({0x04, 0x03, 0x02, 0x02, 0x00, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x01, 0x07, 0x00, 0x02, 0x02, 0x02, 0x01, 0x03, 0x01, 0x18, 0x05, 0x00, 0x00, 0x01, 0x03, 0x01, 0x19, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00});
    mDb.emplace(info40->code(), info40);

    auto info41 = std::make_shared<CardInfo>();
    info41->setCode("KGL/S79-063");
    info41->setLevel(0);
    info41->setCost(0);
    info41->setSoul(1);
    info41->setPower(1000);
    info41->setName("cardName");
    info41->setType(CardType::Char);
    info41->setColor('G');
    info41->addAbility({0x01, 0x03, 0x01, 0x1d, 0x00, 0x08, 0x00, 0x00});
    mDb.emplace(info41->code(), info41);
}

CardDatabase& CardDatabase::get() {
    static CardDatabase instance;
    return instance;
}

std::shared_ptr<CardInfo> CardDatabase::getCard(const std::string &code) {
    if (!mDb.count(code))
        return {};

    return mDb.at(code);
}
