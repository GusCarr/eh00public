// SliderGroup.cpp

#include "SliderGroup.h"

//==============================================================================
SliderGroup::SliderGroup()
{
    const int widthI = (int) (width0 / howMany);

    for (unsigned int I = 0; I < howMany; I++)
    {       
        sliders.add(new juce::Slider(juce::String(I)));

        sliders[I]->setRange(0.0, 1.0);
        sliders[I]->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        sliders[I]->setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
        
        addAndMakeVisible(sliders[I]);
        
        myLookAndFeel.setForegroundColour(juce::Colours::aquamarine);
        myLookAndFeel.setBackgroundColour(juce::Colours::blue);        
        myLookAndFeel.setFillBack(true);        
        myLookAndFeel.setWithBar(true);
        

        sliders[I]->setLookAndFeel(&myLookAndFeel);
        sliders[I]->setBounds(x0 + widthI * I, y0, widthI, height0);

        sliders[I]->addListener(this);
    }
}

void SliderGroup::setName(const juce::String nameIn)
{
    name = nameIn;
}

void SliderGroup::paint(juce::Graphics &g)
{
    // pass.
}

float SliderGroup::getSliderValue(const int Index)
{
    return sliders[Index]->getValue();
}

void SliderGroup::resized()
{
    // DBG("width0 = " + juce::String(width0));

    const int widthI = (int) (width0 / howMany);

    for (unsigned int I = 0; I < howMany; I++)
    {
        sliders[I]->setBounds(x0 + widthI * I, y0, widthI, height0);
    }   
    DBG("  x0=" + juce::String(x0) +
        ", y0=" + juce::String(y0) +
        ", width0=" + juce::String(width0) +
        ", height0=" + juce::String(height0));    
}

void SliderGroup::sliderValueChanged(juce::Slider* theSlider)
{
    DBG(" Group: " + name + ",  slider:" + juce::String(theSlider->getName()) + ", value =" + juce::String(theSlider->getValue()));
}

// ====
SliderGroup::~SliderGroup() // Destructor.
{
    for (unsigned int I = 0; I < howMany; I++)
    {
        sliders[I]->removeListener(this);
    }
}

// eof.-