#include "animation.h"
#include "gameEngine.h"

void CombatUltAnim(UIElement* target, UIElement* overlay) {
    Transform t = target->GetTransform();
    t.position.y -= 150;
    t.opacity = 1.0f;
    target->AddTweeny(t,2000,target->GetTransform(),OUT);

    overlay->GetTransform().opacity = 0.8f;
    Transform overlayT = overlay->GetTransform();
    overlayT.opacity = 0.0f;
    overlay->AddTweeny(overlay->GetTransform(),1500,overlayT,OUT);
}
void CombatSkillAnim(UIElement* target) {
    std::cout << "skill Anim" <<std::endl;
    Transform t = target->GetTransform();
    t.position.y -= 300;
    t.opacity = 1.0f;
    target->AddTweeny(t,1500,target->GetTransform(),OUT);
}
void PostFightAnim(std::vector<UIElement*>& elements, std::vector<Character*> winners, GameMats matsgot, FightNodeStars starsGot) {
    for (auto& e : elements) {
        if (e->GetName() == "char1") {
            e->SetTexture(winners.at(0)->GetSprite()->GetTextureAt("base"));

            Transform t = e->GetTransform();
            e->GetTransform().position.x += 150;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "char2") {
            e->SetTexture(winners.at(1)->GetSprite()->GetTextureAt("base"));

            Transform t = e->GetTransform();
            e->GetTransform().position.x += 150;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "char3") {
            e->SetTexture(winners.at(2)->GetSprite()->GetTextureAt("base"));

            Transform t = e->GetTransform();
            e->GetTransform().position.x += 150;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "tier1Mat" ||e->GetName() == "tier2Mat" || e->GetName() == "tier3Mat") {
            Transform t = e->GetTransform();
            e->GetTransform().position.x -= 100;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "tier1Gained") {
            auto label = dynamic_cast<Text*>(e);
            label->ChangeText(std::to_string(matsgot.tier1).c_str());

            Transform t = e->GetTransform();
            e->GetTransform().position.x -= 100;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "tier2Gained") {
            auto label = dynamic_cast<Text*>(e);
            label->ChangeText(std::to_string(matsgot.tier2).c_str());

            Transform t = e->GetTransform();
            e->GetTransform().position.x -= 100;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "tier3Gained") {
            auto label = dynamic_cast<Text*>(e);
            label->ChangeText(std::to_string(matsgot.tier3).c_str());

            Transform t = e->GetTransform();
            e->GetTransform().position.x -= 100;
            e->GetTransform().opacity = 0.0f;
            t.opacity = 1.0f;
            e->AddTweeny(t,2000,t,OUT);
        }
        else if (e->GetName() == "lessthan5") {
            auto star = dynamic_cast<Sprite*>(e);
            star->ChangeState(starsGot.lessThan5 ? "got" : "base");
        }
        else if (e->GetName() == "noDeaths") {
            auto star = dynamic_cast<Sprite*>(e);
            star->ChangeState(starsGot.noDeaths ? "got" : "base");
        }
        else if (e->GetName() == "lessthan10") {
            auto star = dynamic_cast<Sprite*>(e);
            star->ChangeState(starsGot.lessThan10 ? "got" : "base");
        }
    }
}