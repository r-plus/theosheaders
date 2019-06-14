#import <Preferences/Preferences.h>
#import <libprefs/prefs.h>

static inline id FilteredSpecifiers(id _specifiers)
{
    NSMutableArray *removals = [NSMutableArray array];

    for (id spec in _specifiers) {
        if (![PSSpecifier environmentPassesPreferenceLoaderFilter:[spec propertyForKey:PLFilterKey]])
            [removals addObject:spec];
    }

    // remove
    if (removals.count > 0) {
      NSMutableArray *newSpecifiers = [_specifiers mutableCopy];
      [_specifiers release];
      [newSpecifiers removeObjectsInArray:removals];
      _specifiers = newSpecifiers;
    }

    return _specifiers;
}
