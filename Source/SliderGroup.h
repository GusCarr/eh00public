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
    void setName (const juce::String nameIn);
    void paint (juce::Graphics&) override;
    float getSliderValue(const int Index);
    void resized() override;
    void sliderValueChanged(juce::Slider* theSlider) override;

private:        // sliderGroup.h

    // Private attributes.
    unsigned int howMany{8};    // how many sliders this group has.
    int x0{0};                  // initial position in x.
    int y0{0};                  // initial position in y.
    int width0{200};            // initial width.
    int height0{100};           // initial height.

    juce::String        name;    
    SliderLookAndFeel   myLookAndFeel;       
    juce::OwnedArray<juce::Slider> sliders;

    // Private methods.
    //        ---  none.

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderGroup)
};

// eof.-