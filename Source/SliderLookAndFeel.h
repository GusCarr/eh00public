// SliderLookAndFeel.h

#pragma once

#include <JuceHeader.h>

class SliderLookAndFeel : public juce::LookAndFeel_V4
{
public:

    // Constructor & destructor.
    SliderLookAndFeel() {};
    ~SliderLookAndFeel() = default;


    // Public attributes.
    bool withBar{false};
    bool fillBack{false};    
    juce::Colour backgroundColour{juce::Colours::darkgrey};
    juce::Colour foregroundColour{juce::Colours::orange};
    

    // Public methods.
    void setWithBar(const bool choice)
    {
        withBar = choice;
    }

    void setFillBack(const bool choice)
    {
        fillBack = choice;
    }

    void setForegroundColour(const juce::Colour inColour) 
    {
        foregroundColour = inColour;
    };

    void setBackgroundColour(const juce::Colour inColour) 
    {
        backgroundColour = inColour;
    };

    void drawLinearSlider (juce::Graphics& g,
                            int x, 
                            int y, 
                            int width, 
                            int height, 
                            float sliderPos,
                            float minSliderPos,
                            float maxSliderPos,
                            const juce::Slider::SliderStyle theStyle,
                            juce::Slider& theSlider) override
    {
        juce::Rectangle<int> sliderArea(x, y, width, height);

        if (fillBack) 
        {
            g.setColour (backgroundColour); 
            g.fillRect (sliderArea); 
        }

        // level indicator.
        g.setColour (foregroundColour);

        int theHeight{(height - (int) sliderPos + y + 1)};

        if (!withBar) 
        {
            theHeight = 1;
        }

        g.fillRect (x, juce::jmax(1, (int) sliderPos), width, juce::jmax(2, theHeight));

        // outer frame.        
         if (!fillBack) 
        {
            g.setColour (backgroundColour); 
            g.drawRect (sliderArea);        
        }        
    };    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderLookAndFeel);                            
};

// eof.-
