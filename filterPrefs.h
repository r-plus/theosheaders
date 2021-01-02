#import <Preferences/Preferences.h>
#import <libprefs/prefs.h>
#define kPLFilterKey @"pl_filter"

#if !__has_feature(objc_arc)
    static inline id FilteredSpecifiers(id _specifiers)
    {
        NSMutableArray *removals = [NSMutableArray array];

        for (id spec in _specifiers) {
            if (![PSSpecifier environmentPassesPreferenceLoaderFilter:[spec propertyForKey:kPLFilterKey]])
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
#else
    static inline id FilteredSpecifiers(id _specifiers)
    {
        NSMutableArray *removals = [NSMutableArray array];

        for (id spec in _specifiers) {
            NSDictionary *d = [spec propertyForKey:kPLFilterKey];
            if (![PSSpecifier environmentPassesPreferenceLoaderFilter:d])
                [removals addObject:spec];
        }

        // remove
        if (removals.count > 0) {
          NSMutableArray *newSpecifiers = [_specifiers mutableCopy];
          [newSpecifiers removeObjectsInArray:removals];
          _specifiers = newSpecifiers;
        }

        return _specifiers;
    }
#endif
