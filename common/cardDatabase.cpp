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
    info2->setTraits({ "Shuchiin" });
    info2->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x04, 0x15, 0xe3, 0x83, 0xa8, 0xe3, 0x83, 0xbc, 0xef, 0xbc, 0x81, 0xe3, 0x83, 0xa1, 0xe3, 0x83, 0xbc, 0xe3, 0x83, 0xb3, 0xe2, 0x99, 0xaa, 0x00, 0x09, 0x03, 0x01, 0x07, 0x02, 0x00, 0x01, 0x03, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x05, 0x00, 0x02, 0x04, 0x01, 0x03, 0x03, 0x02, 0x00, 0x01, 0x03, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x09, 0x02, 0x00, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x01, 0x00, 0x02, 0x05, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x02, 0x01, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00});
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
    info5->setName("ヨー！メーン♪");
    info5->setType(CardType::Climax);
    info5->setColor('B');
    info5->setTriggers({ TriggerIcon::Treasure });
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
    info6->addAbility({0x02, 0x05, 0x00, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x06, 0x01, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0xa0, 0x0f, 0x00, 0x00, 0x01, 0x00});
    info6->addAbility({0x02, 0x05, 0x00, 0x01, 0x02, 0x01, 0x02, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x00, 0x01, 0x03, 0x01, 0x01, 0x00, 0x04, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x05, 0x01, 0x03, 0x01, 0x06, 0x00, 0x04, 0x05, 0x00, 0x01, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01, 0x06, 0x02, 0x02, 0x00, 0x03, 0x01, 0x03, 0x00, 0x02, 0x01, 0x00, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x00, 0x24, 0x00, 0x03, 0x01, 0x00, 0x00});
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
    info8->addAbility({0x01, 0x03, 0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x00, 0x00});
    info8->addAbility({0x02, 0x05, 0x00, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x04, 0x15, 0xe3, 0x83, 0xa8, 0xe3, 0x83, 0xbc, 0xef, 0xbc, 0x81, 0xe3, 0x83, 0xa1, 0xe3, 0x83, 0xbc, 0xe3, 0x83, 0xb3, 0xe2, 0x99, 0xaa, 0x00, 0x09, 0x03, 0x01, 0x07, 0x02, 0x00, 0x01, 0x03, 0x02, 0x02, 0x01, 0x01, 0x03, 0x08, 0x53, 0x68, 0x75, 0x63, 0x68, 0x69, 0x69, 0x6e, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x05, 0x00, 0x02, 0x04, 0x01, 0x03, 0x03, 0x02, 0x00, 0x01, 0x03, 0x04, 0x01, 0x02, 0x02, 0x01, 0x01, 0x09, 0x02, 0x00, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x02, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0xd0, 0x07, 0x00, 0x00, 0x01, 0x00, 0x02, 0x05, 0x00, 0x02, 0x05, 0x00, 0x03, 0x01, 0x0d, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x02, 0x01, 0x04, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00});
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
    info17->setTraits({ "Shuchiin" });
    info17->addAbility({0x02, 0x05, 0x00, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x03, 0x00, 0x01, 0x04, 0x00, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x02, 0x06, 0x03, 0x01, 0x06, 0x00, 0x02, 0x02, 0x00, 0x01, 0x03, 0x00, 0x01, 0x02, 0x02, 0x01, 0x01, 0x07, 0x00, 0x02, 0x00, 0x01, 0x02, 0x04, 0x00, 0x01, 0x02, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02, 0x01, 0x00, 0x00});
    info17->addAbility({0x03, 0x04, 0x01, 0x04, 0x01, 0x01, 0x02, 0x04, 0x00, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00, 0x02, 0x01, 0x01, 0x03, 0x01, 0x0a, 0x00, 0xd0, 0x07, 0x00, 0x00, 0x02, 0x00});
    mDb.emplace(info17->code(), info17);
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
