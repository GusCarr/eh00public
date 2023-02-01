//  SliderGroup.h
#pragma once

#include <stdio.h>
#include <JuceHeader.h> // included more than once to have intellisense during coding.
#include "SliderLookAndFeel.h"


class SliderGroup : public juce::Component,
                    public juce::Slider::Listener
{
public:

    // Constructor & destructor.
    SliderGroup ();
    ~SliderGroup();

    // Public attributes.
    //        ---  none.

    // Public methods.
    void realise(const int howMany);
    // void init(const int howMany, int ix, int iy, int iW, int iH);
    void setName (const juce::String nameIn);
    void setForegroundColour(const juce::Colour inForegroundColour);
    void setBackgroundColour(const juce::Colour inBackgroundColour);
    void setFrameColour(const juce::Colour inColour);    
    void setBackgroundAlpha(const float inAlpha);
    void setWithFrame(bool choice);

    void paint (juce::Graphics&) override;
    float getSliderValue(const int Index);
    void setSliderValue(const int Index, const double value);
    void resetValues(const double value);
    void resized() override;
    void sliderValueChanged(juce::Slider* theSlider) override;

    

private:        // sliderGroup.h

    // Private attributes.
    unsigned int howMany{0};    // how many sliders this group has.
    int x0{0};                  // initial position in x.
    int y0{0};                  // initial position in y.
    int width0{100};            // initial width.
    int height0{50};           // initial height.

    juce::Colour foregroundColour{juce::Colours::black};
    juce::Colour backgroundColour{juce::Colours::orange};
    juce::Colour frameColour{juce::Colours::darkgrey};
    bool withFrame{false};

    float backgroundAlpha{0.6};    

    juce::String        name{"name"};    
    SliderLookAndFeel   myLookAndFeel;  

    juce::OwnedArray<juce::Slider> sliders;

    // Private methods.
    //        ---  none.

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderGroup)
};

// eof.-