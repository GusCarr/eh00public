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
    bool withFrame{false};    
    bool fillBack{false};        
    
    juce::Colour foregroundColour{juce::Colours::orange};
    juce::Colour backgroundColour{juce::Colours::darkgrey};
    juce::Colour frameColour{juce::Colours::darkgrey};

    float backgroundAlpha{1.0};
    

    // Public methods.
    void setWithBar(const bool choice)
    {
        withBar = choice;
    }

    void setWithFrame(const bool choice)
    {
        withFrame = choice;
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
        backgroundColour = inColour.withAlpha(backgroundAlpha);
    };

    void setFrameColour(const juce::Colour inColour) 
    {
        frameColour = inColour; //.withAlpha(backgroundAlpha);
    };

    void setBackgroundAlpha(const float Alpha) 
    {
        backgroundAlpha = Alpha;
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
        juce::Rectangle<float> sliderArea(x, y, width, height);

        if (fillBack) 
        {
            g.setColour (backgroundColour); 
            g.fillRect (sliderArea); 
        }

        // level indicator.
        g.setColour (foregroundColour);

        int theHeight{(height - (int) (sliderPos + y))};

        if (!withBar) 
        {
            theHeight = 1;
        }

        g.fillRect (x, juce::jmax(0.5 * width, sliderPos - 2.0), width, juce::jmax(2, theHeight));

        // outer frame.        
         if (withFrame) 
        {
            g.setColour (frameColour); 
            g.drawRect (sliderArea);        
        }        
    };    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderLookAndFeel);                            
};

// eof.-
